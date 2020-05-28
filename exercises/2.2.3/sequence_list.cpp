#include <iostream>
#define ElemType int

// Structure declaration
typedef struct{
    ElemType *data;                                 // Data
    int length;                                     // Length of the list
    int MaxSize;                                    // Maximum size of the list
}SeqList;

// Basic operations
void InitList(SeqList &L, int size);                // Initialize a sequence list
int Length(SeqList L);                              // Return the length of given sequence list
int LocateElem(SeqList L, ElemType e);              // Return the first position of given value
ElemType GetElem(SeqList L, int p);                 // Return value in given position
int ListInsert(SeqList &L, int p, ElemType e);      // Insert element e to given position
int ListDelete(SeqList &L, int p, ElemType &e);     // Delete element in given opsition, return its value to e
void Printlist(SeqList L);                          // Print sequence list
int Empty(SeqList L);                               // To judge if the list is empty
void DestroyList(SeqList &L);                       // Destroy given list and release space

int main()
{
    int temp = 0;
    SeqList L;
    InitList(L, 10);
    std::cout << "length after initialization:" << Length(L) << "\n";
    std::cout << "empty:" << Empty(L) << "\n";
    std::cout << ListInsert(L, 1, 1) << "\n";
    std::cout << ListInsert(L, 2, 2) << "\n";
    std::cout << ListInsert(L, 3, 3) << "\n";
    Printlist(L);
    std::cout << Length(L) << "\n";
    std::cout << ListInsert(L, 5, 5) << "\n";
    std::cout << ListDelete(L, 2, temp) << "\n";
    std::cout << temp << "\n";
    Printlist(L);
    std::cout << Length(L) << "\n";
    DestroyList(L);
    std::cout << "empty:" << Empty(L) << "\n";
    return 0;
}


void InitList(SeqList &L, int size)
{
    // Initialize a sequence list

    // Allocate space, initialize it as empty list
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
    // Return the first position of given value
    // If not found return 0

    // Scan list
    for(int i=0; i<L.length; i++)
    {
        // If the value matches, return index
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

    // If position is not legal, insertion fails
    if(p<1 || p>L.length+1)
        return 0;
    // If list is full, insertion fails
    if(L.length >= L.MaxSize)
        return 0;
    // Move elements
    for(int i=L.length; i>p; i--)
        L.data[i] = L.data[i-1];
    // Insert
    L.data[p-1] = e;
    L.length++;
    return 1;
}

int ListDelete(SeqList &L, int p, ElemType &e)
{
    // Delete element in given opsition and return its value to e
    // If succeeded return 1, else return 0

    // If position is not legal, deletion fails
    if(p<1 || p>L.length)
        return 0;
    // If list is empty, deletion fails
    if(L.length <= 0)
        return 0;
    // Save the value of element to be deleted
    e = L.data[p-1];
    // Move elements
    for(int i=p; i<L.length; i++)
        L.data[i-1] = L.data[i];
    L.length--;
    return 1;
}

void Printlist(SeqList L)
{
    // Print sequence list

    // Scan list and print each element
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

    // Release space
    delete [] L.data;
    L.length = 0;
    L.MaxSize = 0;
}