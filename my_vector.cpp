#include <stdexcept>
#include <algorithm>
#include "my_vector.hpp"

myVct::myVct() : size(0), capacity(0), ptr(nullptr) {}
myVct::myVct(int cap) : size(0), capacity(cap), ptr((int*)malloc(cap*sizeof(int))) {}

int myVct::get_size() const
{
    return size;
}

int myVct::get_capacity() const
{
    return capacity;
}

void myVct::scale_up()
{
    if (capacity == 0)
    {
        capacity = 1;
    }
    else
    {
        capacity *= 2;
    }
    move(capacity);
}


void myVct::scale_down()
{
    capacity = capacity * 2 / 3;
    move(capacity);
}

void myVct::move(int capacity){
    int *new_ptr = (int *)malloc(capacity * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        *(new_ptr + i) = *(ptr + i);
    }
    free(ptr);
    ptr = new_ptr;
}

void myVct::push_back(int value)
{
    if (capacity < size + 1)
    {
        scale_up();
    }
    *(ptr + size) = value;
    size++;
}

void myVct::pop_back()
{
    if (size == 0)
    {
        return;
    }
    size--;
    if (size == 0)
    {
        free(ptr);
        ptr = nullptr;
        capacity = 0;
    }

    if (capacity / 4 == size)
        scale_down();
}

int myVct::get_value(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("out of range");
    return *(ptr + index);
}
