#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int value;

    Node()
    {
        this->left = nullptr;
        this->right = nullptr;
        this->value = 0;
    }
};

class BST
{
    Node* root = nullptr;

    Node* _add(Node* current, int element)
    {
        if (current == nullptr)
        {
            Node* item = new Node();
            item->value = element;
            return item;
        }
        else
        {
            if (element < current->value)
            {
                current->left = _add(current->left, element);
            }
            if (element > current->value)
            {
                current->right = _add(current->right, element);
            }
        }

        return current;
    }

    Node* _delete(Node* current, int element)
    {
        if (current == nullptr)
        {
            return nullptr;
        }
        if (element < current->value)
        {
            current->left = _delete(current->left, element);
        }
        if (element > current->value)
        {
            current->right = _delete(current->right, element);
        }
        if (element == current->value)
        {
            if (current->left == nullptr && current->right == nullptr)
            {
                delete current;
                return nullptr;
            }
            if (current->right == nullptr)
            {
                Node* tempLeft = current->left;
                delete current;
                return tempLeft;
            }
            if (current->left == nullptr)
            {
                Node* tempRight = current->right;
                delete current;
                return tempRight;
            }
            if (current->left != nullptr && current->right != nullptr)
            {
                Node* swapWith = current->right;
                while (swapWith->left != nullptr)
                {
                    swapWith = swapWith->left;
                }
                int temp = current->value;
                current->value = swapWith->value;
                swapWith->value = temp;
                current->right = _delete(current->right, swapWith->value);
            }
        }
        return current;
    }

    bool _isExists(Node* current, int element)
    {
        if (current != nullptr)
        {
            if (element == current->value)
            {
                return true;
            }
            if (element < current->value)
            {
                return _isExists(current->left, element);
            }
            if (element > current->value)
            {
                return _isExists(current->right, element);
            }
        }

        return false;
    }

    void _preorder(Node* current)
    {
        if (current != nullptr)
        {
            cout << current->value << " ";
            _preorder(current->left);
            _preorder(current->right);
        }
    }

    void _inorder(Node* current)
    {
        if (current != nullptr)
        {
            _inorder(current->left);
            cout << current->value << " ";
            _inorder(current->right);
        }
    }

    void _postorder(Node* current)
    {
        if (current != nullptr)
        {
            _postorder(current->left);
            _postorder(current->right);
            cout << current->value << " ";
        }
    }

public:
    void add(int element)
    {
        root = _add(root, element);
    }

    void removeElement(int element)
    {
        root = _delete(root, element);
    }

    bool isExists(int element)
    {
        return _isExists(root, element);
    }

    void print()
    {
        _inorder(root);
        cout << endl;
    }

    void levelorder()
    {
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            if (current != nullptr)
            {
                cout << current->value << " ";
            }
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }
};

int main()
{
    BST b;
    b.add(10);
    b.add(8);
    b.add(20);
    b.add(11);
    b.add(1);
    b.add(4);
    b.add(0);

    //b.removeElement(4);

    b.print();

    //cout << b.isExists(10);

    b.levelorder();

    return 0;
}
