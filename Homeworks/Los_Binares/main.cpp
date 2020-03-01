#include <iostream>

using namespace std;

long cnt = -1;

struct Node
{
    long data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(long value)
    {
        this->data = value;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

class BST
{
private:
    Node* root = nullptr;

    Node* insert_element(long value, Node* current)
    {
        if (current == nullptr)
        {
            Node* l = new Node(value);
            l->left = nullptr;
            l->right = nullptr;
            return l;
        }
        if (value < current->data)
        {
            current->left = insert_element(value, current->left);
        }
        if (value > current->data)
        {
            current->right = insert_element(value, current->right);
        }

        return current;
    }

    bool exists(long value, Node* current)
    {
        if (current != nullptr)
        {
            if (current->data == value)
            {
                cnt++;
                return true;
            }
            if (value < current->data)
            {
                cnt++;
                return exists(value, current->left);
            }
            if (value > current->data)
            {
                cnt++;
                return exists(value, current->right);
            }
        }
        return false;
    }

    void preorder(Node* current)
    {
        if (current != nullptr)
        {
            cout << current->data << " ";
            preorder(current->left);
            preorder(current->right);
        }
    }

public:
    BST()
    {

    }
    ~BST()
    {
        delete root;
    }

    void insert(long value)
    {
        root = insert_element(value, root);
    }

    bool searching(long value)
    {
        return exists(value, root);
    }

    void print()
    {
        preorder(root);
        cout << endl;
    }
};

int main()
{
    long N;
    long K;

    cin >> N;
    cin >> K;

    long value;

    BST b;

    for (long i = 0; i < N; i++)
    {
        cin >> value;
        b.insert(value);
    }

    long element;

    for (long i = 0; i < K; i++)
    {
        cin >> element;
        if (b.searching(element) == true)
        {
            cout << cnt << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        cnt = -1;
    }

    return 0;
}
