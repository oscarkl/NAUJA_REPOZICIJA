#pragma once
#include <iostream>

template <typename T> class Vektorius
{
private:
    T* Array;
    int size;
    int capacity;
public:
    Vektorius();
    Vektorius(const Vektorius& rhs);
    Vektorius(int elements, int value = 0);
    ~Vektorius();

    void push_back(T value);
    void pop_back();
    bool Empty() const;
    int Size() const;
    int Capacity() const;

    T operator*() const;

    bool operator==(const Vektorius& rhs) const;
    bool operator!=(const Vektorius& rhs) const;

    Vektorius& operator =(const Vektorius& rhs) const;
    Vektorius& operator++() const;
    Vektorius operator++(int);

    T& operator[](int index);   
    T& at(int index);
    T& front();
    T& back() const;

    void insert(int index, int value);
    void erase(int index);
    void erase(int index1, int index2);
    void clear();

    Vektorius begin() const;
    Vektorius end() const;

};
