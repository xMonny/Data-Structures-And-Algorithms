#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Directory
{
    Directory* parent;
    string word;
    map<string, Directory*> table;

    Directory()
    {
        this->word = "/";
        this->parent = nullptr;
    }
};

class Path
{
    Directory* root = new Directory();
    Directory* current = root;

public:
    void make_directory(string directory)
    {
        map<string, Directory*>::iterator it = current->table.find(directory);

        if (it != current->table.end())
        {
            cout << "Directory already exists" << endl;
            return;
        }
        Directory* new_directory = new Directory();
        new_directory->parent = current;
        new_directory->word = directory;
        current->table.insert(make_pair(directory, new_directory));
    }

    void change_directory(string directory)
    {
        if (directory == "..")
        {
            if (current == root)
            {
                cout << "No such directory" << endl;
                return;
            }
            current = current->parent;
            return;
        }
        map<string, Directory*>::iterator it = current->table.find(directory);
        if (it == current->table.end())
        {
            cout << "No such directory" << endl;
            return;
        }
        current = it->second;
    }

    void print_whole_directory()
    {
        Directory* remember = current;
        if (remember != root)
        {
            vector<string> s;
            while (remember != root)
            {
                s.push_back(remember->word);
                remember = remember->parent;
            }

            for (int i = s.size()-1; i >= 0; i--)
            {
                cout << "/" << s[i];
            }
        }
        cout << "/" << endl;
    }

    void print(map<string, Directory*> t, Directory* remember)
    {
        map<string, Directory*>::iterator it;
        for (it = t.begin(); it != t.end(); it++)
        {
            if (it->second->parent != remember)
            {
                break;
            }
            cout << it->first << " ";
            print(it->second->table, remember);
        }
    }

    void print()
    {
        print(current->table, current);
        cout << endl;
    }
};

int main()
{
    int N;
    cin >> N;

    string expression;
    string directory;

    Path path;

    for (int i = 0; i < N; i++)
    {
        cin >> expression;
        if (expression == "mkdir")
        {
            cin >> directory;
            path.make_directory(directory);
        }
        if (expression == "cd")
        {
            cin >> directory;
            path.change_directory(directory);
        }
        if (expression == "ls")
        {
            path.print();
        }
        if (expression == "pwd")
        {
            path.print_whole_directory();
        }
    }

    return 0;
}
