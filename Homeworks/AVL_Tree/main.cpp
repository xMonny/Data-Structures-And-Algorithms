#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void swapElements(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

int max(int one, int two)
{
    if (one > two)
    {
        return one;
    }
    return two;
}

struct Node
{
    int height = 0;
	double value;
	Node *left = nullptr;
	Node *right = nullptr;

	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}

    void getHeight()
    {
        height = 0;
        if (left != nullptr)
        {
            height = max(height, left->height+1);
        }
        if (right != nullptr)
        {
            height = max(height, right->height+1);
        }
    }

    int leftHeight()
    {
        if (left != nullptr)
        {
            return left->height+1;
        }
        return 0;
    }

    int rightHeight()
    {
        if (right != nullptr)
        {
            return right->height+1;
        }
        return 0;
    }

    int balanceTree()
    {
        return leftHeight()-rightHeight();
    }

    void rightRotate()
    {
        if (left == nullptr)
        {
            return;
        }

        Node* leftRight = this->left->right;
        Node* oldRight = this->right;

        swapElements(this->value, this->left->value);
        this->right = this->left;
        this->left = this->left->left;
        this->right->left = leftRight;
        this->right->right = oldRight;
    }

    void leftRotate()
    {
        if (right == nullptr)
        {
            return;
        }

        Node* rightLeft = this->right->left;
        Node* oldLeft = this->left;

        swapElements(this->value, this->right->value);
        this->left = this->right;
        this->right = this->right->right;
        this->left->right = rightLeft;
        this->left->left = oldLeft;
    }

    void resetHeight()
    {
        if (left != nullptr)
        {
            left->getHeight();
        }
        if (right != nullptr)
        {
            right->getHeight();
        }

        this->getHeight();
    }

    void fixTree()
    {
        if (balanceTree() < -1)
        {
            if (right->balanceTree() < -1)
            {
                this->leftRotate();
                resetHeight();
            }
            else if (right->balanceTree() >= 1)
            {
                right->rightRotate();
                this->leftRotate();
                resetHeight();
            }
        }
        else
        {
            if (balanceTree() > 1)
            {
                if (left->balanceTree() >= 1)
                {
                    this->rightRotate();
                    resetHeight();
                }
                else
                {
                    if (left->balanceTree() <= -1)
                    {
                        left->leftRotate();
                        this->rightRotate();
                        resetHeight();
                    }
                }
            }
        }
    }
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

    Node* _insert(Node* current, double data)
    {
        if (current == nullptr)
        {
            return new Node(data, nullptr, nullptr);
        }
        if (data < current->value)
        {
            current->left = _insert(current->left, data);
        }
        if (data > current->value)
        {
            current->right = _insert(current->right, data);
        }

        current->getHeight();
        current->fixTree();
        return current;
    }

    Node* _remove(Node* current, double data)
    {
        if (current == nullptr)
        {
            return nullptr;
        }

        if (data < current->value)
        {
            current->left = _remove(current->left, data);
        }
        if (data > current->value)
        {
            current->right = _remove(current->right, data);
        }
        if (data == current->value)
        {
            if (current->left == nullptr && current->right == nullptr)
            {
                delete current;
                return nullptr;
            }
            if (current->left == nullptr)
            {
                Node* tempRight = current->right;
                delete current;
                return tempRight;
            }
            if (current->right == nullptr)
            {
                Node* tempLeft = current->left;
                delete current;
                return tempLeft;
            }
            if (current->left != nullptr && current->right != nullptr)
            {
                Node* swapWith = current->right;
                while (swapWith->left != nullptr)
                {
                    swapWith = swapWith->left;
                }
                current->value = swapWith->value;
                current->right = _remove(current->right, swapWith->value);
            }
        }

        current->getHeight();
        current->fixTree();

        return current;
    }

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	void add(double value)
	{
        if (contains(value) == true)
        {
            cout << value << " already added" << endl;
            return;
        }
       root = _insert(root, value);
	}

	void remove(double value)
	{
        if (contains(value) == false)
        {
            cout << value << " not found to remove" << endl;
            return;
        }
       root = _remove(root, value);
	}

bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
        cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
    cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}
