#pragma once
#include <iostream>
//#include <ctime>
#include <chrono>
#include <thread>

#include "ListSequence.h"
#include "ArraySequence.h"
#include "Tests.h"
#include "Sorter.h"
#include "Exception.h"


using namespace std;
using namespace std::chrono;

void Filling();
void menu();
	
template <typename T>
bool cmp(T a, T b) {
    if (a < b)
        return true;
    else return false;
}

float RandomFloat(float min, float max)//random
{
    return (float)(rand()) / RAND_MAX * (max - min) + min;
}
int RandomInteger(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
string RandomString() {
    int len = RandomInteger(0, 30);
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


    return tmp_s;
}




template <class T>
void CompareAlg(T* arr, int size, int type) {
    double TIME[3];
    if (type == 1) {
        Sequence<T>* a = new LinkedListSequence<T>(arr, size);
        //time_t timestart = clock();
        high_resolution_clock::time_point t31 = high_resolution_clock::now();
        BubbleSort(a, size, cmp);
        high_resolution_clock::time_point t32 = high_resolution_clock::now();
        auto duration31 = duration_cast<microseconds>(t32 - t31).count();

        //time_t timeend = clock();
        TIME[0] = duration31;//difftime(timeend, timestart); //время сортировки

        Sequence<T>* b = new LinkedListSequence<T>(arr, size);
        //time_t timestart1 = clock();
        high_resolution_clock::time_point t33 = high_resolution_clock::now();
        QuickSort(b, cmp, 0, size - 1);
        high_resolution_clock::time_point t34 = high_resolution_clock::now();
        auto duration33 = duration_cast<microseconds>(t34 - t33).count();
        //time_t timeend1 = clock();
        TIME[1] = duration33; //difftime(timeend1, timestart1);

        Sequence<T>* c = new LinkedListSequence<T>(arr, size);
        //time_t timestart2 = clock();
        high_resolution_clock::time_point t35 = high_resolution_clock::now();
        InsertSort(c, cmp);
        high_resolution_clock::time_point t36 = high_resolution_clock::now();
        auto duration35 = duration_cast<microseconds>(t36 - t35).count();
        //time_t timeend2 = clock();
        TIME[2] = duration35;//difftime(timeend2, timestart2);

        delete[] arr;

        cout << "B/Q: " << TIME[0] / TIME[1] << endl;
        cout << "B/I: " << TIME[0] / TIME[2] << endl;
        cout << "Q/I: " << TIME[1] / TIME[2] << endl;

        cout << endl;

        cout << "1 - new sort, 2 - main menu, 3 - exit" << endl;

        int choice;
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            Filling();
        }
        if (choice == 2) {
            menu();
        }
        if (choice == 3) {
            exit(0);
        }
        else throw Exception("Incorrect parameter");

    }
    if (type == 2) {
        Sequence<T>* a = new ArraySequence<T>(arr, size);
        //time_t timestart = clock();
        high_resolution_clock::time_point t41 = high_resolution_clock::now();
        BubbleSort(a, size, cmp);
        high_resolution_clock::time_point t42 = high_resolution_clock::now();
        auto duration41 = duration_cast<microseconds>(t42 - t41).count();
        //time_t timeend = clock();
        TIME[0] = duration41;//difftime(timeend, timestart); //время сортировки

        Sequence<T>* b = new ArraySequence<T>(arr, size);
        //time_t timestart1 = clock();
        high_resolution_clock::time_point t43 = high_resolution_clock::now();
        QuickSort(b, cmp, 0, size - 1);
        high_resolution_clock::time_point t44 = high_resolution_clock::now();
        auto duration43 = duration_cast<microseconds>(t44 - t43).count();
        //time_t timeend1 = clock();
        TIME[1] = duration43;//difftime(timeend1, timestart1);

        Sequence<T>* c = new ArraySequence<T>(arr, size);  
        //time_t timestart2 = clock();
        high_resolution_clock::time_point t45 = high_resolution_clock::now();
        InsertSort(c, cmp);
        high_resolution_clock::time_point t46 = high_resolution_clock::now();
        auto duration45 = duration_cast<microseconds>(t46 - t45).count();
        //time_t timeend2 = clock();
        TIME[2] = duration45;//difftime(timeend2, timestart2);

        delete[] arr;

        cout << "B/Q: " << TIME[0] / TIME[1] << endl;
        cout << "B/I: " << TIME[0] / TIME[2] << endl;
        cout << "Q/I: " << TIME[1] / TIME[2] << endl;

        cout << endl;

        cout << "1 - new sort, 2 - main menu, 3 - exit" << endl;

        int choice;
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            Filling();
        }
        if (choice == 2) {
            menu();
        }
        if (choice == 3) {
            exit(0);
        }
        else throw Exception("Incorrect parameter");

    }
};


template <class T>
void Sorts(T* arr, int size, int type, int method) {
    if (type == 1) {
        cout << "Select sort type: 1 - bubble, 2 - quick, 3 - insert or 4 - main menu, 5 - exit, 6 - compare" << endl;
        int choice;
        cin >> choice;
        Sequence<T>* b = new LinkedListSequence<T>(arr, size);
        if (method == 1) {
            cout << endl;
            cout << "RECENT: ";
            for (int i = 0; i < b->GetLength(); i++) {
                cout << b->Get(i) << " ";
            }
            cout << endl;
        }

        if (choice == 1) {
            cout << endl;
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            BubbleSort(b, size, cmp);
           
            high_resolution_clock::time_point t2 = high_resolution_clock::now();

            auto duration1 = duration_cast<microseconds>(t2 - t1).count();
            cout << "BUBBLESORT: ";
            for (int i = 0; i < size; i++) {
                cout << b->Get(i) << " ";
            }
            cout << endl;
            cout << "TIME: " << duration1 << " microseconds" << endl;



            Sorts(arr, size, type, method);
        }
        if (choice == 2) {
            cout << endl;
            high_resolution_clock::time_point t3 = high_resolution_clock::now();
            QuickSort(b, cmp, 0, size - 1);
            high_resolution_clock::time_point t4 = high_resolution_clock::now();

            auto duration2 = duration_cast<microseconds>(t4 - t3).count();
            cout << "QUICKSORT: ";
            for (int i = 0; i < size; i++) {
                cout << b->Get(i) << " ";
            }
            cout << endl;
            cout << "TIME: " << duration2 << "microseconds" << endl;

            Sorts(arr, size, type, method);
        }
        if (choice == 3) {
            cout << endl;
            high_resolution_clock::time_point t5 = high_resolution_clock::now();
            InsertSort(b, cmp);
            high_resolution_clock::time_point t6 = high_resolution_clock::now();
            auto duration3 = duration_cast<microseconds>(t6 - t5).count();
            cout << "INSERTSORTT: ";
            for (int i = 0; i < size; i++) {
                cout << b->Get(i) << " ";
            }
            cout << endl;
            cout << "TIME: " << duration3 << " microseconds" << endl;

            Sorts(arr, size, type, method);
        }
        if (choice == 4) {
            delete[] arr;
            cout << endl;
            menu();
        }
        if (choice == 5) {
            delete[] arr;
            exit(0);
        }
        if (choice == 6) {
            CompareAlg(arr, size, type);
        }
        else throw Exception("Incorrect parametr");
    }
    if (type == 2) {
        Sequence<T>* b = new ArraySequence<T>(arr, size);
        //ArraySequence<T> b = Sequence<T>(arr, size);

        cout << "Select sort type: 1 - bubble, 2 - quick, 3 - insert or 4 - main menu, 5 - exit" << endl;
        int choice;
        cin >> choice;

        if (method == 1) {
            cout << endl;
            cout << "RECENT: ";
            for (int i = 0; i < b->GetLength(); i++) {
                cout << b->Get(i) << " ";
            }
            cout << endl;
        }

        if (choice == 1) {
            cout << endl;
            high_resolution_clock::time_point t7 = high_resolution_clock::now();
            BubbleSort(b, size, cmp);
            high_resolution_clock::time_point t8 = high_resolution_clock::now();
            auto duration4 = duration_cast<microseconds>(t8 - t7).count();
            cout << "BUBBLESORT: ";
            for (int i = 0; i < size; i++) {
                cout << b->Get(i) << " ";
            }
            cout << endl;
            cout << "TIME: " << duration4 << " microseconds" << endl;

            Sorts(arr, size, type, method);
        }
        if (choice == 2) {
            cout << endl;
            high_resolution_clock::time_point t9 = high_resolution_clock::now();
            QuickSort(b, cmp, 0, size - 1);
            high_resolution_clock::time_point t10 = high_resolution_clock::now();
            auto duration5 = duration_cast<microseconds>(t10 - t9).count();
            cout << "QUICKSORT: ";
            for (int i = 0; i < size; i++) {
                cout << b->Get(i) << " ";
            }
            cout << endl;
            cout << "TIME: " << duration5 << " microseconds" << endl;

            Sorts(arr, size, type, method);
        }
        if (choice == 3) {
            cout << endl;
            high_resolution_clock::time_point t11 = high_resolution_clock::now();
            InsertSort(b, cmp);
            high_resolution_clock::time_point t12 = high_resolution_clock::now();
            auto duration6 = duration_cast<microseconds>(t12 - t11).count();
            cout << "INSERTSORT: ";
            for (int i = 0; i < size; i++) {
                cout << b->Get(i) << " ";
            }
            cout << endl;
            cout << "TIME: " << duration6 << " microseconds" << endl;

            Sorts(arr, size, type, method);
        }
        if (choice == 4) {
            delete[] arr;
            cout << endl;
            menu();
        }
        if (choice == 5) {
            delete[] arr;
            exit(0);
        }
        else throw Exception("Incorrect parametr");

    }
    else throw Exception("Incorrect parametr");
}


void Filling() {

    cout << "Select type of implementation: 1 - list, 2 - array" << endl;
    int type;
    cin >> type;
    cout << endl;

    cout << "Enter size" << endl;
    int size;
    cin >> size;
    cout << endl;

    cout << "Select a data type: 1 - int, 2 - float, 3 - string" << endl;
    int data;
    cin >> data;
    cout << endl;

    cout << "Select a data entry method: 1 - random, 2 - by yourself" << endl;
    int method;
    cin >> method;
    cout << endl;

    cout << "1 - compare, 2 - sorts" << endl;
    int z;
    cin >> z;
    cout << endl;

    if (data == 1) {
        if (method == 2) {
            int* arr = new int[size];
            cout << "Add elements" << endl;
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            if (z == 1) {
                CompareAlg(arr, size, type);
            }
            if (z == 2) {
                Sorts(arr, size, type, method);
            }
            else throw Exception("Incorrect parametr");
        }
        if (method == 1) {
            int* arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = RandomInteger(-10000, 10000);
            }
            if (z == 1) {
                CompareAlg(arr, size, type);
            }
            if (z == 2) {
                Sorts(arr, size, type, method);
            }
            else throw Exception("Incorrect parametr");
        }
        else throw Exception("Incorrect parametr");
    }

    if (data == 2) {
        if (method == 2) {
            float* arr = new float[size];
            cout << "Add elements" << endl;
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            if (z == 1) {
                CompareAlg(arr, size, type);
            }
            if (z == 2) {
                Sorts(arr, size, type, method);
            }
            else throw Exception("Incorrect parametr");
        }
        if (method == 1) {
            float* arr = new float[size];
            for (int i = 0; i < size; i++) {
                arr[i] = RandomFloat(-1000.0, 1000.0);
            }
            if (z == 1) {
                CompareAlg(arr, size, type);
            }
            if (z == 2) {
                Sorts(arr, size, type, method);
            }
            else throw Exception("Incorrect parametr");
        }
        else throw Exception("Incorrect parametr");
    }

    if (data == 3) {
        if (method == 2) {
            string* arr = new string[size];
            cout << "Add elements" << endl;
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            if (z == 1) {
                CompareAlg(arr, size, type);
            }
            if (z == 2) {
                Sorts(arr, size, type, method);
            }
            else throw Exception("Incorrect parametr");
        }
        if (method == 1) {
            string* arr = new string[size];
            for (int i = 0; i < size; i++) {
                arr[i] = RandomString();
            }
            if (z == 1) {
                CompareAlg(arr, size, type);
            }
            if (z == 2) {
                Sorts(arr, size, type, method);
            }
            else throw Exception("Incorrect parametr");
        }
        else throw Exception("Incorrect parametr");
    }
}


void menu()
{
    cout << "1 - tests, 2 - algorithms, 3 - exit" << endl;
    int MainChoice;
    cin >> MainChoice;
    cout << endl;
    if (MainChoice == 1) {
       DynamicArrayTests();
       LinkedListTests();
        cout << endl;

        menu();
    }
    if (MainChoice == 2) {

        Filling();
    }
    if (MainChoice == 3) {

        exit(0);
    }
    else throw Exception("Incorrect parametr");
};
