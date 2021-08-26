#pragma once
#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* items;

public:
    ArraySequence()
    {
        this->items = new DynamicArray<T>();
    }

    ArraySequence(T* items, int count)
    {
        this->items = new DynamicArray<T>(items, count);
    }

    ArraySequence(const DynamicArray<T>& array)
    {
        this->items = new DynamicArray<T>(array);
    }

    ArraySequence(const ArraySequence<T>& sequence)
    {
        this->items = new DynamicArray<T>(*sequence.items);
    }

    virtual ~ArraySequence()
    {
        Free();
    }

    void Free()
    {
        if (this->items != nullptr)
        {
            delete(this->items);
            this->items = nullptr;
        }
    }


    T GetFirst()
    {
        return this->items->Get(0);
    }

    T GetLast()
    {
        return this->items->Get(GetLength() - 1);
    }

    T Get(int index)
    {
        return this->items->Get(index);
    }

    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
    {
        DynamicArray<T> subsequence;
        subsequence.Resize(endIndex - startIndex + 1);

        for (int i = startIndex; i <= endIndex; i++)
        {
            subsequence.Set(i - startIndex, this->items->Get(i));
        }

        ArraySequence<T>* result = new ArraySequence(subsequence);
        return result;
    }

    int GetLength()
    {
        return this->items->GetSize();
    }

    void Append(const T& item)
    {
        this->items->Resize(this->items->GetSize() + 1);
        this->items->Set(this->items->GetSize() - 1, item);
    }

    void Prepend(const T& item)
    {
        this->items->Resize(this->items->GetSize() + 1);
        for (int i = this->items->GetSize() - 1; i > 0; i--)
        {
            this->items->Set(i, this->items->Get(i - 1));
        }
        this->items->Set(0, item);
    }

    void Set(const T& item, int index)
    {
        this->items->Set(index, item);
    }

    void InsertAt(const T& item, int index)
    {
        this->items->Resize(this->items->GetSize() + 1);
        for (int i = this->items->GetSize() - 1; i > index; i--)
        {
            this->items->Set(i, this->items->Get(i - 1));
        }
        this->items->Set(index, item);
    }

    void DeleteAt(int index)
    {
        int j = index;
        for (int i = index + 1; i < this->items->GetSize(); i++, j++)
        {
            this->items->Set(j, this->items->Get(i));
        }
        this->items->Resize(this->items->GetSize() - 1);
    }

    ArraySequence<T>* Concat(Sequence<T>* list)
    {
        DynamicArray<T> concat(*(this->items));

        int size = concat.GetSize();
        concat.Resize(size + list->GetLength());

        for (int i = 0; i < list->GetLength(); i++)
        {
            concat.Set(size + i, list->Get(i));
        }

        ArraySequence<T>* result = new ArraySequence(concat);
        return result;
    }
};