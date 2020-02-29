#pragma once

class IntStack
{
private:
    int* elements;
    int stackSize;
    int stackMaxSize;
    void sizeChange();

public:
    IntStack();
    IntStack(const IntStack&);
    IntStack& operator=(const IntStack&);

    void push(int);
    void changeElement(int, int); //position, value
    void insertElement(int, int); //position, value
    void removeElement(int); //position
    int getBegin() const;
    int getEnd() const;

    int getElement(int) const; //position
    int pop();

    void printReversed() const;
    void printNormal() const;

    friend IntStack sortStack(IntStack&);

    ~IntStack();
};
