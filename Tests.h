#pragma once
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Exception.h"


bool DynamicArrayResizeTests()
{
    int a[3] = { 1, 2, 3 };
    DynamicArray<int> a2(a, 3);

    a2.Resize(5);
    int size = a2.GetSize();
    int el0 = a2.Get(0);
    int el1 = a2.Get(1);
    int el2 = a2.Get(2);
    int el3 = a2.Get(3);
    int el4 = a2.Get(4);

    bool result = (size == 5) && (el0 == 1) && (el1 == 2) && (el2 == 3)
        && (el3 == 0) && (el4 == 0);
    result ? printf("DynamicArrayResizeTests OK\n") : printf("DynamicArrayResizeTests ERROR\n");
    return result;
}

bool DynamicArrayGetSizeTests()
{
    int a[4] = { 4, 5, 6, 7 };
    DynamicArray<int> a2(a, 4);
    int size = a2.GetSize();

    bool result = (size == 4);
    result ? printf("DynamicArrayGetSizeTests OK\n") : printf("DynamicArrayGetSizeTests ERROR\n");
    return result;
}

bool DynamicArrayGetTests()
{
    int a[4] = { 4, 5, 6, 7 };
    DynamicArray<int> a2(a, 4);
    int el2 = a2.Get(1);

    bool outofrange = false;
    try
    {
        a2.Get(10);
    }
    catch (const Exception& ex)
    {
        outofrange = true;
    }

    bool result = (el2 == 5) && (outofrange == true);
    result ? printf("DynamicArrayGetTests OK\n") : printf("DynamicArrayGetTests ERROR\n");
    return result;
}


bool DynamicArraySetTests()
{
    DynamicArray<int> a1;

    a1.Resize(3);
    a1.Set(0, 0);
    a1.Set(2, 2);
    a1.Set(1, 1);

    int v1 = a1.Get(0);
    int v2 = a1.Get(1);
    int v3 = a1.Get(2);

    bool outofrange = false;
    try
    {
        a1.Set(7, 40);
    }
    catch (const Exception& ex)
    {
        outofrange = true;
    }


    bool result = (v1 == 0) && (v2 == 1) && (v3 == 2) && (outofrange == true);
    result ? printf("DynamicArraySetTests OK\n") : printf("DynamicArraySetTests ERROR\n");
    return result;
}


bool DynamicArrayConstructor1Tests()
{
    DynamicArray<int> a1;

    int size = a1.GetSize();

    bool result = (size == 0);
    result ? printf("DynamicArrayConstructor1Tests OK\n") : printf("DynamicArrayConstructor1Tests ERROR\n");
    return result;
}

bool DynamicArrayConstructor2Tests()
{
    int a[4] = { 4, 5, 6, 7 };
    DynamicArray<int> a2(a, 4);
    int size = a2.GetSize();
    int el1 = a2.Get(0);
    int el2 = a2.Get(1);
    int el3 = a2.Get(2);
    int el4 = a2.Get(3);

    bool result = (size == 4) && (el1 == 4) && (el2 == 5) && (el3 == 6) && (el4 == 7);
    result ? printf("DynamicArrayConstructor2Tests OK\n") : printf("DynamicArrayConstructor2Tests ERROR\n");
    return result;
}

bool DynamicArrayConstructor3Tests()
{
    DynamicArray<int> a2(4);
    int size = a2.GetSize();
    int el1 = a2.Get(0);
    int el2 = a2.Get(1);
    int el3 = a2.Get(2);
    int el4 = a2.Get(3);

    bool result = (size == 4) && (el1 == 0) && (el2 == 0) && (el3 == 0) && (el4 == 0);
    result ? printf("DynamicArrayConstructor3Tests OK\n") : printf("DynamicArrayConstructor3Tests ERROR\n");
    return result;
}

bool DynamicArrayConstructor4Tests()
{
    int a[3] = { 6, 4, 5 };
    DynamicArray<int> a1(a, 3);

    DynamicArray<int> a3(a1);
    int size = a3.GetSize();
    int el1 = a3.Get(0);
    int el2 = a3.Get(1);
    int el3 = a3.Get(2);

    bool result = (size == 3) && (el1 == 6) && (el2 == 4) && (el3 == 5);
    result ? printf("DynamicArrayConstructor4Tests OK\n") : printf("DynamicArrayConstructor4Tests ERROR\n");
    return result;
}



void DynamicArrayTests()
{
    DynamicArrayResizeTests();
    DynamicArrayGetSizeTests();
    //DynamicArrayGetTests();
    //DynamicArraySetTests();
    DynamicArrayConstructor1Tests();
    DynamicArrayConstructor2Tests();
    DynamicArrayConstructor3Tests();
    DynamicArrayConstructor4Tests();

}

bool LinkedListAppendTests()
{
    LinkedList<int> a1;
    int length1 = a1.GetLength();

    a1.Append(1);
    a1.Append(2);

    int length2 = a1.GetLength();
    int v1 = a1.GetFirst();

    bool result = (length2 - length1 == 2) && (v1 == 1);
    result ? printf("LinkedListAppendTests OK\n") : printf("LinkedListAppendTests ERROR\n");
    return result;
}

bool LinkedListPrependTests()
{
    LinkedList<int> a1;
    int length1 = a1.GetLength();

    a1.Prepend(1);
    a1.Prepend(2);

    int length2 = a1.GetLength();
    int v1 = a1.GetFirst();

    bool result = (length2 - length1 == 2) && (v1 == 2);
    result ? printf("LinkedListPrependTests OK\n") : printf("LinkedListPrependTests ERROR\n");
    return result;
}

bool LinkedListInsertAtTests()
{
    LinkedList<int> a1;
    int length1 = a1.GetLength();

    a1.InsertAt(0, 0);
    a1.InsertAt(2, 1);
    a1.InsertAt(1, 1);

    int length2 = a1.GetLength();
    int v1 = a1.Get(0);
    int v2 = a1.Get(1);
    int v3 = a1.Get(2);

    bool outofrange = false;
    try
    {
        a1.InsertAt(7, 40);
    }
    catch (const Exception& ex)
    {
        outofrange = true;
    }


    bool result = (length2 - length1 == 3) && (v1 == 0) && (v2 == 1) && (v3 == 2) && (outofrange == true);
    result ? printf("LinkedListInsertAtTests OK\n") : printf("LinkedListInsertAtTests ERROR\n");
    return result;
}

bool LinkedListGetFirstTests()
{
    int a[4] = { 4, 5, 6, 7 };
    LinkedList<int> a2(a, 4);
    int el1 = a2.GetFirst();

    bool outofrange = false;
    try
    {
        LinkedList<int> a;
        a.GetFirst();
    }
    catch (const Exception& ex)
    {
        outofrange = true;
    }

    bool result = (el1 == 4) && (outofrange == true);
    result ? printf("LinkedListGetFirstTests OK\n") : printf("LinkedListGetFirstTests ERROR\n");
    return result;
}

bool LinkedListGetLastTests()
{
    int a[4] = { 4, 5, 6, 7 };
    LinkedList<int> a2(a, 4);
    int el4 = a2.GetLast();

    bool outofrange = false;
    try
    {
        LinkedList<int> a;
        a.GetLast();
    }
    catch (const Exception& ex)
    {
        outofrange = true;
    }

    bool result = (el4 == 7) && (outofrange == true);
    result ? printf("LinkedListGetLastTests OK\n") : printf("LinkedListGetLastTests ERROR\n");
    return result;
}

bool LinkedListGetTests()
{
    int a[4] = { 4, 5, 6, 7 };
    LinkedList<int> a2(a, 4);
    int el2 = a2.Get(1);

    bool outofrange = false;
    try
    {
        a2.Get(10);
    }
    catch (const Exception& ex)
    {
        outofrange = true;
    }

    bool result = (el2 == 5) && (outofrange == true);
    result ? printf("LinkedListGetTests OK\n") : printf("LinkedListGetTests ERROR\n");
    return result;
}

bool LinkedListGetLengthTests()
{
    int a[4] = { 4, 5, 6, 7 };
    LinkedList<int> a2(a, 4);
    int length = a2.GetLength();

    bool result = (length == 4);
    result ? printf("LinkedListGetLengthTests OK\n") : printf("LinkedListGetLengthTests ERROR\n");
    return result;
}

bool LinkedListConstructor1Tests()
{
    int a[4] = { 4, 5, 6, 7 };
    LinkedList<int> a2(a, 4);
    int length = a2.GetLength();
    int el1 = a2.GetFirst();
    int el2 = a2.Get(1);
    int el3 = a2.Get(2);
    int el4 = a2.GetLast();

    bool result = (length == 4) && (el1 == 4) && (el2 == 5) && (el3 == 6) && (el4 == 7);
    result ? printf("LinkedListConstructor1Tests OK\n") : printf("LinkedListConstructor1Tests ERROR\n");
    return result;
}

bool LinkedListConstructor2Tests()
{
    int a[3] = { 6, 4, 5 };
    LinkedList<int> a1(a, 3);

    LinkedList<int> a3(a1);
    int length = a3.GetLength();
    int el1 = a3.GetFirst();
    int el2 = a3.Get(1);
    int el3 = a3.Get(2);

    bool result = (length == 3) && (el1 == 6) && (el2 == 4) && (el3 == 5);
    result ? printf("LinkedListConstructor2Tests OK\n") : printf("LinkedListConstructor2Tests ERROR\n");
    return result;
}

bool LinkedListConcatTests()
{
    int a[3] = { 1, 2, 3 };
    LinkedList<int> a1(a, 3);

    int b[4] = { 4, 5, 6, 7 };
    LinkedList<int> a4(b, 4);

    LinkedList<int>* p1 = a1.Concat(&a4);
    int length = p1->GetLength();
    int el1 = p1->Get(0);
    int el2 = p1->Get(1);
    int el3 = p1->Get(2);
    int el4 = p1->Get(3);
    int el5 = p1->Get(4);
    int el6 = p1->Get(5);
    int el7 = p1->Get(6);

    p1->Free();
    bool result = (length == 7) && (el1 == 1) && (el2 == 2) && (el3 == 3)
        && (el4 == 4) && (el5 == 5) && (el6 == 6) && (el7 == 7);
    result ? printf("LinkedListConcatTests OK\n") : printf("LinkedListConcatTests ERROR\n");
    return result;
}

bool LinkedListGetSubListTests()
{
    int a[7] = { -3, -4, 1, 2, 3, 5, 6 };
    LinkedList<int> a1(a, 7);

    LinkedList<int>* p2 = a1.GetSubList(2, 4);
    int length = p2->GetLength();
    int el1 = p2->Get(0);
    int el2 = p2->Get(1);
    int el3 = p2->Get(2);

    bool outofrange = false;
    try
    {
        a1.GetSubList(0, 20);
    }
    catch (const Exception& ex)
    {
        outofrange = true;
    }

    p2->Free();
    bool result = (length == 3) && (el1 == 1) && (el2 == 2) && (el3 == 3) && (outofrange == true);
    result ? printf("LinkedListSubSequenceTests OK\n") : printf("LinkedListSubSequenceTests ERROR\n");
    return result;
}


void LinkedListTests()
{
    LinkedListAppendTests();
    LinkedListPrependTests();
    //LinkedListInsertAtTests();
    LinkedListGetFirstTests();
    LinkedListGetLastTests();
    LinkedListGetTests();
    LinkedListGetTests();
    LinkedListConstructor1Tests();
    LinkedListConstructor2Tests();
    LinkedListConcatTests();
    LinkedListGetSubListTests();
};