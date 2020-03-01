#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Trie
{
    map<char, Trie*> table;
    bool isEnd = false;
    int prefix = 0;
};

void add(Trie* node, string word)
{
    Trie* current = node;
    for (int i = 0; i < word.size(); i++)
    {
        char symbol = word[i];
        Trie* help = current->table[symbol];
        if (help == nullptr)
        {
            help = new Trie();
            current->table[symbol] = help;
        }
        current = help;
        current->prefix++;
    }
    current->isEnd = true;
}

int getNumber(Trie* node, string pref)
{
    Trie* current = node;
    for (int i = 0; i < pref.size(); i++)
    {
        char symbol = pref[i];
        Trie* help = current->table[symbol];
        if (help == nullptr)
        {
            return 0;
        }
        current = help;
    }
    return current->prefix;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    string word;
    string prefix;
    int arr[Q];
    Trie* root=new Trie();
    for (int i = 0; i < N; i++)
    {
        cin >> word;
        add(root,word);
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> prefix;
        arr[i] = getNumber(root, prefix);
    }
    for (int i = 0; i < Q; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
