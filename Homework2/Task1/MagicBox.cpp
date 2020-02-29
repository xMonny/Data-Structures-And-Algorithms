#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "MagicBox.h"

template <class T>
MagicBox<T>::MagicBox()
{
    length = 0;
    maxSize = 10;
    values = new T[maxSize];
}

template <class T>
MagicBox<T>::MagicBox(const MagicBox &box)
{
    length = box.length;
    maxSize = box.maxSize;

    values = new T[maxSize];

    for (int i = 0; i < length; i++)
    {
        values[i] = box.values[i];
    }
}

template <class T>
MagicBox<T>& MagicBox<T>::operator=(const MagicBox &box)
{
    if (this != &box)
    {
        delete[] values;

        length = box.length;
        maxSize = box.maxSize;

        values = new T[maxSize];

        for (int i = 0; i < length; i++)
        {
            values[i] = box.values[i];
        }
    }
    return *this;
}

template <class T>
void MagicBox<T>::changeSize()
{
    maxSize*=2;

    T* helpArr = new T[maxSize];

    for (int i = 0; i < length; i++)
    {
        helpArr[i] = values[i];
    }

    delete[] values;
    values = helpArr;
}

template <class T>
void MagicBox<T>::insert(T val)
{
    if (length == maxSize)
    {
        changeSize();
    }

    values[length] = val;
    length++;
}

int errorChange = 0;
template <class T>
void MagicBox<T>::change_element(int index, T val)
{
    if (index <= length)
    {
        values[index] = val;
    }

    else
    {
        errorChange++;
    }
}

int errorPush = 0;
template <class T>
void MagicBox<T>::push_in(int pos, T val)
{
    if(pos <= length)
    {
        if (length == maxSize)
        {
            changeSize();
        }

        for (int i = length; i > pos; i--)
        {
            values[i] = values[i-1];
        }

        values[pos] = val;
        length++;
    }

    else
    {
        errorPush++;
    }
}

int errorPop = 0;
int helpEliminate = 0;
template <class T>
void MagicBox<T>::pop()
{
    if (length == 0)
    {
        errorPop++;
    }

    else
    {
        srand(time(NULL));
        int RandIndex = rand()%length;
        eliminated = values[RandIndex];

        for (int i = RandIndex; i < length-1; i++)
        {
            values[i] = values[i+1];
        }

        helpEliminate++;
        length--;
    }
}

template <class T>
void MagicBox<T>::list() const
{
    if (errorChange > 0)
    {
        std::cout << "Invalid position in changing!" << std::endl;
        errorChange = 0;
    }

    if (errorPush > 0)
    {
        std::cout << "Invalid position! You can't push there!" << std::endl;
        errorPush = 0;
    }

    if (errorPop > 0)
    {
        std::cout << "No elements to pop!" << std::endl;
        errorPop = 0;
    }

    if (errorChange == 0 && errorPop == 0 && errorPush == 0)
    {
        std::cout << "Participants: ";
        for(int i = 0; i < length; i++)
        {
            std::cout << values[i] << " ";
        }
        std::cout << std::endl;
        if (helpEliminate > 0)
        {
            std::cout << "Get out: " << eliminated << std::endl;
            helpEliminate = 0;
        }
    }
}

template <class T>
MagicBox<T>::~MagicBox()
{
    delete[] values;
}
