#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

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

class LinkedList
{
public:
    void add(int val, int pos)
    {
        if (pos >= 0 && pos <= length)
        {
            Node* item = new Node();
            item->value = val;
            if (pos == 0)
            {
                if (head == nullptr)
                {
                    this->head = item;
                    this->tail = item;
                    length++;
                }
                else
                {
                    item->next = head;
                    head = item;
                    length++;
                }
            }
            else
            {
                if (pos == length)
                {
                    Node* current = head;
                    Node* previous = nullptr;
                    while (current != nullptr)
                    {
                        previous = current;
                        current = current->next;
                    }
                    previous->next = item;
                    this->tail = previous;
                    length++;
                }
                else
                {
                    Node* current = head;

                    for (int i = 1; i < pos; i++)
                    {
                        current = current->next;
                    }
                    item->next = current->next;
                    current->next = item;
                    length++;
                }
            }
        }
        else
        {
            Node* item = new Node();
            item->value = val;
            if (head == nullptr)
            {
                head = item;
                tail = item;
                length++;
            }
            else
            {
                this->tail->next = item;
                this->tail = item;
                length++;
            }
            cout << "add_last";
        }
    }

    void print()
    {
        if (head != nullptr)
        {
            Node* current = head;

            while (current != nullptr)
            {
                cout << current->value << "#";
                current = current->next;
            }
        }
    }

    void remove(int pos)
    {
        if (pos >= 0 && pos < length)
        {
            if (head != nullptr)
            {
                if (pos == 0)
                {
                    Node* oldHead = head;
                    head = head->next;
                    delete oldHead;
                    length--;
                }
                else
                {
                    Node* current = head;
                    Node* previous;

                    for (int i = 1; i <= pos; i++)
                    {
                        previous = current;
                        current = current->next;
                    }
                    previous->next = current->next;
                    if (previous->next == nullptr)
                    {
                        tail = previous;
                    }
                    length--;
                }
            }
            else
            {
                cout << "remove_failed";
            }
        }
        else
        {
            cout << "remove_failed";
        }
    }

    void reverse()
    {
        if (head != nullptr)
        {
            Node* current = head;
            Node* previous = nullptr;
            Node* help = nullptr;

            tail = head;

            while (current != nullptr)
            {
                previous = current;
                current = current->next;
                previous->next = help;
                help = previous;
            }
            head = previous;
        }
    }

    void remove_all(int val)
    {
        if (head != nullptr)
        {
            Node* current = head;
            Node* previous = nullptr;

            int check = 0;

            while (current->next != nullptr)
            {
                if (current->value == val)
                {
                    if (current == head)
                    {
                        Node* remember = head;
                        head = head->next;
                        check++;
                        length--;
                    }
                    else
                    {
                        previous->next = current->next;
                        check++;
                        if (previous->next == nullptr)
                        {
                            tail = previous;
                        }
                        length--;
                    }
                }
                if (check == 0)
                {
                    previous = current;
                }
                else
                {
                    check = 0;
                }
                current = current->next;
                if (current->next == nullptr && current->value == val)
                {
                    if (previous != nullptr)
                    {
                        previous->next = nullptr;
                        tail = previous;
                        length--;
                    }
                    else
                    {
                        head = nullptr;
                        tail = nullptr;
                        length--;
                    }
                }
            }
        }
    }

    void group(int a, int b)
    {
        if (a >= 0 && a < length && b >= 0 && b < length)
        {
            if (a > b)
            {
                cout << "fail_grouping";
                return;
            }
            if (head != nullptr)
            {
                Node* current = head;
                Node* previous = nullptr;
                int sum = 0;
                int check = 0;
                int start = 0;
                for (int i = 0; i <= b; i++)
                {
                    if (i == a || start > 0)
                    {
                        if (current != head)
                        {
                            start++;
                            sum+=current->value;
                            check++;
                            previous->next = current->next;
                            length--;
                        }
                        else
                        {
                            start++;
                            sum+=current->value;
                            head = head->next;
                            check++;
                            length--;
                        }
                    }
                    if (check == 0)
                    {
                        previous = current;
                    }
                    else
                    {
                        check = 0;
                    }
                    current = current->next;
                }
                add(sum, a);
            }
        }
        else
        {
            cout << "fail_grouping";
        }
    }

    void count(int val)
    {
        if (head != nullptr)
        {
            Node* current = head;
            int cnt = 0;
            while (current != nullptr)
            {
                if (current->value == val)
                {
                    cnt++;
                }
                current = current->next;
            }
            cout << cnt;
        }
    }

    void is_palindrome()
    {
        if (head != nullptr)
        {
            stack<int> s;

            Node* current = head;

            while (current != nullptr)
            {
                s.push(current->value);
                current = current->next;
            }
            current = head;

            while (!s.empty())
            {
                int top = s.top();
                s.pop();
                if (current->value != top)
                {
                    cout << "false";
                    return;
                }
                current = current->next;
            }
            cout << "true";
            return;
        }
        else
        {
            cout << "true";
            return;
        }
    }

    ~LinkedList()
    {
        Node* current = head;

        while (current != nullptr)
        {
            Node* remember = current->next;
            delete current;
            current = remember;
        }
        head = nullptr;
        tail = nullptr;
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;

    int length = 0;
};

int main() {
    int cases;
    std::cin >> cases;
    for (int i = 0; i < cases; i++) {
        LinkedList ll;
        int ops;
        std::string op;
        std::cin >> ops;
        for (int j = 0; j < ops; j++) {
            std::cin >> op;

            if (op == "count") {
                int arg1;
                std::cin >> arg1;
                ll.count(arg1);
            }

            if (op == "add") {
                int arg1, arg2;
                std::cin >> arg1 >> arg2;
                ll.add(arg1, arg2);
            }

            if (op == "print") {
                ll.print();
            }

            if (op == "remove") {
                int arg1;
                std::cin >> arg1;
                ll.remove(arg1);
            }

            if (op == "reverse") {
                ll.reverse();
            }

            if (op == "remove_all") {
                int arg1;
                std::cin >> arg1;
                ll.remove_all(arg1);
            }

            if (op == "group") {
                int arg1, arg2;
                std::cin >> arg1 >> arg2;
                ll.group(arg1, arg2);
            }

            if (op == "is_palindrom") {
                ll.is_palindrome();
            }
        }

        std::cout << std::endl;

    }
    return 0;
}
