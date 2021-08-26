#pragma once
#include "Sequence.h"

template <class T>
void BubbleSort(Sequence<T>* a, int size, bool (*cmp)(T, T)) {
    T temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (cmp(a->Get(j + 1), a->Get(j))) {//cmp(a->Get(j + 1), a->Get(j))
                // меняем элементы местами
                temp = a->Get(j);
                a->Set(a->Get(j + 1), j);
                a->Set(temp, j + 1);
            }
        }
    }
}

template<class T>
void InsertSort(Sequence<T>* seq, bool (*cmp)(T, T))
{
    T temp;
    int item;
    for (int i = 1; i < seq->GetLength(); i++)
    {
        temp = seq->Get(i);
        item = i - 1;
        while (item >= 0 && !cmp(seq->Get(item), temp)) //>
        {
            seq->Set(seq->Get(item), item + 1);
            seq->Set(temp, item);
            item--;
        }
    }

}

template <class T>
void QuickSort(Sequence<T>* a, bool (*cmp)(T, T), int first, int last) {
    int f = first;
    int l = last;
    T middle = a->Get(round((f + l) / 2));
    while (f <= l){
        while((cmp(a->Get(f), middle)) == 1) {        //
        //while (a->Get(f) < middle) {
            f++;
        }

        while((cmp(middle, a->Get(l))) == 1) { //
        //while (a->Get(l) > middle) {
            l--;
        }
        if (f <= l) {
            T value = a->Get(f);
            a->Set(a->Get(l), f);
            a->Set(value, l);
            f++;
            l--;
        }
    }

    if (l > first) {
        QuickSort(a, cmp, first, l);
    }
    if (l < last) {
        QuickSort(a, cmp, f, last);
    }
}
