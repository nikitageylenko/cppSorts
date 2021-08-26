#pragma once
template <class T>
class Sequence
{
public:
    virtual ~Sequence() {};
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(const int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;

    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual void DeleteAt(int index) = 0;
    virtual void Set(const T& item, int index) = 0;

    virtual void Swap(int index1, int index2)
    {
        T value1 = Get(index1);
        T value2 = Get(index2);

        Set(value1, index2);
        Set(value2, index1);
    }

    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;

    virtual void Free() = 0;
};
