#pragma once
#include <algorithm>

template<typename vector>
class VectorIterator
{
public:
    using ValueType = typename vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

    VectorIterator(PointerType ptr)
        : m_Ptr(ptr) {}
    VectorIterator& operator++()
    {
        m_Ptr++;
        return *this;
    }

    VectorIterator operator++(int)
    {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }
    VectorIterator& operator--()
    {
        m_Ptr--;
        return *this;
    }

    VectorIterator operator--(int)
    {
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index)
    {
        return *(m_Ptr + index);
    }
    PointerType operator->()
    {
        return m_Ptr;
    }
    ReferenceType operator*()
    {
        return *m_Ptr;
    }
    bool operator==(const VectorIterator& other) const
    {
        return m_Ptr == other.m_Ptr;
    }
    bool operator!=(const VectorIterator& other) const
    {
        return !(*this == other);
    }
private:
    PointerType m_Ptr;
};


template<typename T>
class vector
{
private:
    T* Data = nullptr;

    size_t Size = 0; //used memory
    size_t capacity = 0; // available memory

public:
    using ValueType = T;
    using Iterator = VectorIterator<vector<T>>;
    vector() //constructor
    {
        ReAlloc(10);
    }
    vector(const vector& rhs) //copy
        {
            Size = rhs.Size;
            capacity = rhs.capacity;
            Data = rhs.Data;
        }

    ~vector() { delete[] Data; }//destructor

    vector& operator=(const vector& a) { //operator=
        if (this == &a)
        {
            return *this;
        }
        Data = a.Data;
        Size = a.Size;
        capacity = a.capacity;

        return *this;
    }

    void push_back(const T& value) // add new element to back
    {
        if (Size >= capacity)
        {
            ReAlloc(capacity * 100);
        }

        Data[Size] = value;
        Size++;
    }

    const T& operator[](size_t index)const //access at index
    {
        return Data[index];
    }

    T& operator[](size_t index) //access at index and edit
    {
        return Data[index];
    }

    size_t size() const { return Size; } //size of container

    size_t Capacity() const { return capacity; } //size of capacity

    void assign(size_t count, const T& value) {
        ReAlloc(count);
        for (int i = 0; i <= count; i++)
        {
            Data[Size] = value;
            Size++;

        }
    }

    T& front() //access first element
    {
        return Data[0];
    }

    T& back() //access last element
    {
        return Data[Size - 1];
    }
    T& at(int index) {//access element
        return Data[index];
    }

    void insert(int index, T value)
    {

        if (Size != capacity) {
            for (int i = Size - 1; i >= index; i--) {
                Data[i + 1] = Data[i];
            }
            Data[index] = value;
            Size++;
        }
        else {
            capacity *= 2;
            T* newarr = new T[capacity];
            for (int i = 0; i < Size; i++) {
                newarr[i] =Data[i];
            }
            delete[] Data;
            Data = newarr;
            insert(index, value);
        }
    }
    void erase(int index)
    {
        for (int i = index; i < Size - 1; i++) {
            Data[i] = Data[i + 1];
        }
        Size--;
    }

    const T* data() const //pointer to container
    {
        return Data;
    }

    void shrink_to_fit() //set capacity=size
    {
        capacity = Size;
    }

    void reserve(size_t new_cap)// increase the capacity of the vector
    {
        capacity = new_cap;
    }

    bool empty() const //check if container is empty
    {
        if (Size == 0)
            return true;
        else
            return false;
    }

    void pop_back()
    {
        if (Size > 0)
        {
            Size--;
            Data[Size].~T();
        }

    }

    void clear()
    {
        for (size_t i = 0; i < Size; i++)
        {
            Data[i].~T();
        }
        Size = 0;
    }

    Iterator begin()
    {
        return Iterator(Data);
    }
    Iterator end()
    {
        return Iterator(Data + Size);
    }


private:
    void ReAlloc(size_t newCapacity) //increase capacity of container
    {

        T* newBlock = new T[newCapacity];

        if (newCapacity < Size)
        {
            Size = newCapacity;
        }

        for (size_t i = 0; i < Size; i++)
        {
            newBlock[i] = Data[i];
        }
        delete[] Data;
        Data = newBlock;
        capacity = newCapacity;
    }
};
