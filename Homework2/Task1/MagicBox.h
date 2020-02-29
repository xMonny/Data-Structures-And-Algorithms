#pragma once

template <class T>
class MagicBox
{
private:
    T* values;
    T eliminated;
    int length;
    int maxSize;

    void changeSize();

public:
    MagicBox();
    MagicBox(const MagicBox&);
    MagicBox& operator=(const MagicBox&);

    void insert(T);
    void push_in(int, T); //position, value
    void change_element(int, T); //position, value
    void pop();
    void list() const;

    ~MagicBox();
};
