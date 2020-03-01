#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
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

    //my code
    void insert(int value) {
        root = insert(root, value);
    }

    int level = 0;

    queue<int> levels;

    void printKDistant(int k) {
      queue<Node*> que;
      que.push(root);

        levels.push(level);

        while(!que.empty())
        {
            Node* current = que.front();
            que.pop();
            level = levels.front()+1;
            levels.pop();
            if (current != nullptr && k == 0)
            {
                cout << current->value << " ";
                return;
            }
            if (current->right != nullptr)
            {
                que.push(current->right);
                levels.push(level);
                if (level == k)
                {
                    cout << current->right->value << " ";
                }
            }
            if (current->left != nullptr)
            {
                que.push(current->left);
                levels.push(level);
                if (level == k)
                {
                    cout << current->left->value << " ";
                }
            }
        }
    }
    //end of my code

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
    int k;
    cin >> k;
    tree.printKDistant(k);
    return 0;
}
