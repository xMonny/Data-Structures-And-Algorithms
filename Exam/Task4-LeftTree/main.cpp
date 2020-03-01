#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printLeftProfile()
    {
        queue<Node*> q;
        q.push(root);
        queue<int> levels;
        levels.push(0);

        int last = 0;

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();
            int level = levels.front();
            levels.pop();

            if (level == 0)
            {
                cout << current->value << " ";
            }
            else
            {
                if (level != last)
                {
                    cout << current->value << " ";
                }
            }

            if (current->left != nullptr)
            {
                q.push(current->left);
                levels.push(level+1);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
                levels.push(level+1);
            }
            last = level;
        }
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.printLeftProfile();
    return 0;
}
