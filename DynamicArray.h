#pragma once

#include <stdlib.h>
#include "Exception.h"

template <class T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(T* items, int count);
    DynamicArray(int size);
    DynamicArray(const DynamicArray<T>& dynamicArray);

    ~DynamicArray();

    T Get(int index);
    int GetSize();
    void Set(int index, const T& value);
    void Resize(int newSize);

private:
    T* data;
    int size;
};

template <class T>
DynamicArray<T>::DynamicArray()
{
    data = nullptr;
    size = 0;
}

template <class T>
DynamicArray<T>::DynamicArray(T* items, int count)
{
    data = new T[count];
    //data = (T*)malloc(count * sizeof(T));
    for (int i = 0; i < count; i++)
    {
        data[i] = items[i];
    }
    size = count;
}

template <class T>
DynamicArray<T>::DynamicArray(int size)
{
    data = new T[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = T();
    }
    //data = (T*)calloc(size, sizeof(T));
    this->size = size;
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& dynamicArray)
{
    data = new T[dynamicArray.size];
    //data = (T*)malloc(dynamicArray.size * sizeof(T));
    memcpy(data, dynamicArray.data, dynamicArray.size * sizeof(T));
    size = dynamicArray.size;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    if (data != nullptr)
    {
        delete[] data;
        data = nullptr;
    }
}

template <class T>
T DynamicArray<T>::Get(int index)
{
    if (index >= size || index < 0)
    {
        throw  Exception("IndexOutOfRange");
    }

    return data[index];
}

template <class T>
int DynamicArray<T>::GetSize()
{
    return size;
}

template <class T>
void DynamicArray<T>::Set(int index, const T& value)
{
    if (index >= size || index < 0)
    {
        throw  Exception("IndexOutOfRange");
    }

    data[index] = value;
}

template <class T>
void DynamicArray<T>::Resize(int newSize)
{
    T* data2 = new T[newSize];
    //T* data2 = (T*)calloc(newSize, sizeof(T));

    for (int i = 0; i < newSize; i++)
    {
        if (i < size)
        {
            data2[i] = data[i];
        }
        else
        {
            data2[i] = T();
        }
    }
    delete[] data;
    data = data2;
    size = newSize;
};