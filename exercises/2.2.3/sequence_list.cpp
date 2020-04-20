#include <iostream>
#define ElemType int

// Structure declaration
typedef struct{
    ElemType *data;
    int length;
    int MaxSize;
}SeqList;

// Basic operations
void InitList(SeqList &L, int size);                // Initialize a sequence list
int Length(SeqList L);                              // Return the length of given sequence list
int LocateElem(SeqList L, ElemType e);              // Return the first position with given value
ElemType GetElem(SeqList L, int p);                 // Return value in given position
int ListInsert(SeqList &L, int p, ElemType e);      // Insert element e to given position
int ListDelete(SeqList &L, int p, ElemType &e);     // Delete element in given opsition and return it to e
void Printlist(SeqList L);                          // Print sequence list
int Empty(SeqList L);                               // To judge if the list is empty
void DestroyList(SeqList &L);                       // Destroy given list and release space


void InitList(SeqList &L, int size)
{
    // Initialize a sequence list
    L.data = new ElemType[size];
    L.length = 0;
    L.MaxSize = size;
}

int Length(SeqList L)
{
    // Return the length of given sequence list
    return L.length;
}

int LocateElem(SeqList L, ElemType e)
{
    // Return the first position with given value
    // If not found return 0
    for(int i=0; i<L.length; i++)
    {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}

ElemType GetElem(SeqList L, int p)
{
    // Return value in given position
    return L.data[p-1];
}

int ListInsert(SeqList &L, int p, ElemType e)
{
    // Insert element e to given position
    // If succeeded return 1, else return 0
    if(p<1 || p>L.length+1)
        return 0;
    if(L.length >= L.MaxSize)
        return 0;
    for(int i=L.length; i>p; i--)
        L.data[i] = L.data[i-1];
    L.data[p-1] = e;
    L.length++;
    return 1;
}

int ListDelete(SeqList &L, int p, ElemType &e)
{
    // Delete element in given opsition and return it to e
    // If succeeded return 1, else return 0
    if(p<1 || p>L.length)
        return 0;
    e = L.data[p-1];
    for(int i=p; i<L.length; i++)
        L.data[i-1] = L.data[i];
    L.length--;
    return 1;
}

void Printlist(SeqList L)
{
    // Print sequence list
    for(int i=0; i<L.length; i++)
        std::cout << L.data[i] << " ";
    std::cout << std::endl;
}

int Empty(SeqList L)
{
    // If the list is empty, return 1
    // Else return 0
    return !L.length;
}

void DestroyList(SeqList &L)
{
    // Destroy given list and release space
    delete [] L.data;
    L.length = 0;
}