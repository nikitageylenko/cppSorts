#pragma once
#include <cmath>
#include "ArraySequence.h"

using namespace std;

template <class T>
class ArrImp
{
private:
	Sequence<T>* items;
public:

	ArrImp() {
		this->items = new ArraySequence<T>(); // пустой вектор 
	}

	ArrImp(T* items, int count) {
		this->items = new ArraySequence<T>(items, count); //копирует эл-ты из переданного массива
	}

	T Get(int index) const
	{
		return this->items->Get(index);
	}

	int GetLength() const
	{
		return this->items->GetLength();
	}

	void Append(T value)
	{
		this->items->Append(value);
	}

	void Set(int index, T value) {
		this->items->Set(index, value);
	}

	void InsertAt(T value, const int index) { //вставл€ет эл-т в заданную позицию
		try {
			this->items->InsertAt(value, index);
		}
		catch (Exception& exception) {
			cout << exception.getError();
		}
	}

	void RemoveAt(int index) {
		this->items->RemoveAt(index);
	}
	//___________________________________________________________________________________________

	void BubbleSort(int size) {
		T temp;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (this->Get(j) > this->Get(j + 1)) {
					// мен€ем элементы местами
					temp = this->Get(j);
					this->Set(j, this->Get(j + 1));
					this->Set(j + 1, temp);
				}
			}
		}
	}

	void BubbleSortRev(int size) {
		T temp;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (this->Get(j) < this->Get(j + 1)) {
					// мен€ем элементы местами
					temp = this->Get(j);
					this->Set(j, this->Get(j + 1));
					this->Set(j + 1, temp);
				}
			}
		}
	}

	void InsertSort(int size) {
		T x;
		int i, j;

		for (i = 0; i < size; i++) {  // цикл проходов, i - номер прохода
			x = this->Get(i);

			for (j = i - 1; j >= 0 && this->Get(j) > x; j--)
				this->Set(j + 1, this->Get(j));

			this->Set(j + 1, x);
		}
	}

	void InsertSortRev(int size) {
		T x;
		int i, j;

		for (i = 0; i < size; i++) {  // цикл проходов, i - номер прохода
			x = this->Get(i);
			j = i - 1;
			while (j >= 0 && this->Get(j) < x) {
				this->Set(j + 1, this->Get(j));
				j--;
			}
			this->Set(j + 1, x);
		}
	}

	void QuickSort(int first, int last) {
		int f = first;
		int l = last;
		T middle = this->Get(round((f + l) / 2));
		while (f <= l)
		{
			while (this->Get(f) < middle) {
				f++;
			}
			while (this->Get(l) > middle) {
				l--;
			}
			if (f <= l) {
				T value = this->Get(f);
				this->Set(f, this->Get(l));
				this->Set(l, value);
				f++;
				l--;
			}
		}

		if (l > first) {
			QuickSort(first, l);
		}
		if (l < last) {
			QuickSort(f, last);
		}
	}

	void QuickSortRev(int first, int last) {
		int f = first;
		int l = last;
		T middle = this->Get(round((f + l) / 2));
		while (f <= l)
		{
			while (this->Get(f) > middle) {
				f++;
			}
			while (this->Get(l) < middle) {
				l--;
			}
			if (f <= l) {
				T value = this->Get(f);
				this->Set(f, this->Get(l));
				this->Set(l, value);
				f++;
				l--;
			}
		}

		if (l > first) {
			QuickSortRev(first, l);
		}
		if (l < last) {
			QuickSortRev(f, last);
		}
	}

	~ArrImp() {
		delete this->items;
	}
};
