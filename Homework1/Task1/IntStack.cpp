#include <iostream>
#include "IntStack.h"

IntStack::IntStack()
{
    stackSize = 0;
    stackMaxSize = 10;
    elements = new int[stackMaxSize];
}

IntStack::IntStack(const IntStack& values)
{
    stackSize = values.stackSize;
    stackMaxSize = values.stackMaxSize;

    elements = new int[stackMaxSize];

    for (int i = 0; i < stackSize; i++)
    {
        elements[i] = values.elements[i];
    }
}

IntStack& IntStack::operator=(const IntStack& values)
{
    if (this != &values)
    {
        delete[] elements;

        stackSize = values.stackSize;
        stackMaxSize = values.stackMaxSize;

        elements = new int[stackMaxSize];

        for (int i = 0; i < stackSize; i++)
        {
            elements[i] = values.elements[i];
        }
    }
    return *this;
}

void IntStack::sizeChange()
{
    stackMaxSize*=2;

    int* helpStack = new int[stackMaxSize];

    for (int i = 0; i < stackSize; i++)
    {
        helpStack[i] = elements[i];
    }

    delete[] elements;

    elements = helpStack;
}

void IntStack::push(int newItem)
{
    if (stackSize == stackMaxSize)
    {
        sizeChange();
    }

    elements[stackSize] = newItem;

    stackSize++;
}

void IntStack::changeElement(int position, int value)
{
    if (position <= stackSize)
    {
        elements[position] = value;
    }

    else
    {
        std::cout << "Invalid position!" << std::endl;
    }
}

void IntStack::insertElement(int position, int value)
{
    if (position <= stackSize)
    {
        if (stackSize == stackMaxSize)
        {
            sizeChange();
        }

        for (int i = stackSize; i > position; i--)
        {
            elements[i] = elements[i-1];
        }

        elements[position] = value;
        stackSize++;
    }

    else
    {
        std::cout << "Invalid position!" << std::endl;
    }
}

void IntStack::removeElement(int position)
{
    if (position <= stackSize)
    {
        for (int i = position; i < stackSize-1; i++)
        {
            elements[i] = elements[i+1];
        }
        stackSize--;
    }

    else
    {
        std::cout << "Invalid position!" << std::endl;
    }
}

int IntStack::getBegin() const
{
    if (stackSize != 0)
    {
        return elements[0];
    }

    else
    {
        std::cout << "There are no elements in the stack!" << std::endl;
    }
}

int IntStack::getEnd() const
{
    if (stackSize != 0)
    {
        return elements[stackSize-1];
    }

    else
    {
        std::cout << "There are no elements in the stack!" << std::endl;
    }
}

int IntStack::getElement(int position) const
{
    if (position <= stackSize)
    {
        return elements[position];
    }

    else
    {
        std::cout << "Invalid position!" << std::endl;
    }
}

int IntStack::pop()
{
    if (stackSize != 0)
    {
        stackSize--;
        return elements[stackSize];
    }

    else
    {
        std::cout << "No elements to pop!" << std::endl;
    }
}

IntStack sortStack(IntStack &values)
{
    int stackSize = values.stackSize;
    for (int i = 0; i < stackSize-1; i++)
    {
        for (int j = i+1; j < stackSize; j++)
        {
            if (values.elements[i] > values.elements[j])
            {
                int helper = values.elements[i];
                values.elements[i] = values.elements[j];
                values.elements[j] = helper;
            }
        }
    }
    return values;
}

void IntStack::printReversed() const
{
    for (int i = stackSize-1; i >= 0; i--)
    {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

void IntStack::printNormal() const
{
    for (int i = 0; i < stackSize; i++)
    {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

IntStack::~IntStack()
{
    delete[] elements;
}
