#include "vektorius.h"

template<typename T>
Vektorius<T>::Vektorius()
	:size(0),
	capacity(5),
	Array(new T[capacity])
{
}

template<typename T>
Vektorius<T>::Vektorius(const Vektorius& rhs)
	:size(rhs.size),
	capacity(rhs.capacity),
	Array(new T[capacity])
{
	for (int i = 0; i < rhs.Size(); i++) {
		Array[i] = rhs.Array[i];
	}
}

template<typename T>
Vektorius<T>::Vektorius(int elements, int value)
	:size(elements),
	capacity(elements + 5),
	Array(new T[capacity])
{
	for (int i = 0; i < size; i++) {
		Array[i] = value;
	}
}

template<typename T>
Vektorius<T>::~Vektorius()
{
	delete[] Array;
}

template<typename T>
void Vektorius<T>::push_back(T value) {
	if (size < capacity)
	{
		Array[size] = value;
		++size;
	}
	else 
	{
		capacity *= 2;
		int* newarr = new T[capacity];
		for (int i = 0; i < size; i++) {
			newarr[i] = Array[i];
		}
		newarr[size] = value;
		++size;
		delete[] Array;
		Array = newarr;
	}
}

template<typename T>
void Vektorius<T>::pop_back()
{
	if (size == 0) {
		throw std::exception("pop_back naudojama tusciam vektoriuj!");
	}
	--size;
}

template<typename T>
bool Vektorius<T>::Empty() const
{
	return size == 0;
}

template<typename T>
int Vektorius<T>::Size() const
{
	return size;
}

template<typename T>
int Vektorius<T>::Capacity() const
{
	return capacity;
}

template<typename T>
T Vektorius<T>::operator*() const
{
	return *Array;
}

template<typename T>
bool Vektorius<T>::operator==(const Vektorius& rhs) const
{
	if (Size() != rhs.Size()) {
		return false;
	}	
	for (int i = 0; i < Size(); i++) {
		if (Array[i] != rhs.Array[i]) {
			return false;
		}
	}
	return true;
}

template<typename T>
bool Vektorius<T>::operator!=(const Vektorius& rhs) const
{
	return !(*this == rhs);
}

template<typename T>
Vektorius<T>& Vektorius<T>::operator=(const Vektorius& rhs) const
{
	if (rhs.size > size) {
		delete[] Array;
		capacity = rhs.size;
		Array = new T[capacity];
	}
	for (int i = 0; i < rhs.Size(); i++) {
		Array[i] = rhs.Array[i];
	}
	size = rhs.size;
	return *this;
}

template<typename T>
Vektorius<T>& Vektorius<T>::operator++() const
{
	++Array;
	return Array * this;
}
template<typename T>
Vektorius<T> Vektorius<T>::operator++(int)
{
	Vektorius temp(*this);
	++*this;
	return temp;
}

template<typename T>
T& Vektorius<T>::operator[](int index)
{
	return Array[index];
}

template<typename T>
T& Vektorius<T>::at(int index)
{
	return Array[index];
}

template<typename T>
T& Vektorius<T>::front()
{
	return Array[0];
}

template<typename T>
T& Vektorius<T>::back() const
{
	return Array[size-1];
}

template<typename T>
void Vektorius<T>::insert(int index, int value)
{
	if (size != capacity) {
		for (int i = size-1; i >= index; i--) {
			Array[i+1] = Array[i];
		}
		Array[index] = value;
		size++;
	}
	else {
		capacity *= 2;
		int* newarr = new T[capacity];
		for (int i = 0; i < size ; i++) {
			newarr[i] = Array[i];
		}
		delete[] Array;
		Array = newarr;
		insert(index, value);
	}
}

template<typename T>
void Vektorius<T>::erase(int index)
{
	for (int i = index; i < size - 1; i++) {
		Array[i] = Array[i + 1];
	}
	size--;
}

template<typename T>
void Vektorius<T>::erase(int index1, int index2)
{
	for (int i = index1+1; i < size-index2+index1; i++) {
		Array[i] = Array[i+index1];
	}
	size -= (index2 - index1 - 1);
}

template<typename T>
void Vektorius<T>::clear()
{
	size = 0;
}

template<typename T>
Vektorius<T> Vektorius<T>::begin() const
{
	return Vektorius(Array);
}

template<typename T>
Vektorius<T> Vektorius<T>::end() const
{
	return Vektorius(Array + size);
}
