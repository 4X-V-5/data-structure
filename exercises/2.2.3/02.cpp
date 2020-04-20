#include <iostream>
#include "sequence_list.cpp"

void ReverseList(SeqList &L);

int main()
{
    ElemType temp;
    SeqList L;
    InitList(L, 10);
    for(int i=1; i<6; i++)
        ListInsert(L, i, i);
    ReverseList(L);
    Printlist(L);
    return 0;

}

void ReverseList(SeqList &L)
{
    ElemType temp;
    for(int i=0; i<L.length/2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = temp;
    }
}