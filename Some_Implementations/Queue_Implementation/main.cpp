#include <iostream>

using namespace std;

struct Node
{
    Node* next;
    int value;

    Node()
    {
        this->next = nullptr;
        this->value = 0;
    }
};

class Queue
{
    Node* first = nullptr;
    Node* last = nullptr;

public:
    ~Queue()
    {
        while (first != nullptr)
        {
            Node* previous = first->next;
            delete first;
            first = previous;
        }
    }

    void add(int element)
    {
        Node* item = new Node();
        item->value = element;
        if (isEmpty())
        {
            first = item;
            last = item;
        }
        else
        {
            last->next = item;
            last = item;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node* oldFirst = first;
            first = first->next;
            delete oldFirst;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }

    int getFront() const
    {
        return first->value;
    }

    bool isEmpty() const
    {
        return first == nullptr;
    }
};

int main()
{
    Queue q;
    q.add(3);
    q.add(5);
    q.add(10);
    q.add(9);
    q.add(20);
    q.add(21);

    Queue q1;
    q1 = q;

    while (!q1.isEmpty())
    {
        cout << q1.getFront() << " ";
        q1.pop();
    }

    return 0;
}
