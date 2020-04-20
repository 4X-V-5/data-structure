#include <iostream>
#include "sequence_list.cpp"

int DeleteMin(SeqList &L, ElemType &e);

int main()
{
    ElemType temp;
    SeqList L;
    InitList(L, 10);
    if(!DeleteMin(L, temp))
        std::cout << "Could not delete empty list\n;";
    for(int i=1; i<6; i++)
        ListInsert(L, i, i);
    if(DeleteMin(L, temp))
        std::cout << "Success\n";
    Printlist(L);
    return 0;

}

int DeleteMin(SeqList &L, ElemType &e)
{
    if(L.length == 0)
        return 0;
    int position = 0;
    e = L.data[0];
    for(int i=1; i<L.length; i++)
    {
        if(L.data[i] < e)
        {
            e = L.data[i];
            position = i;
        }
    }
    L.data[position] = L.data[L.length-1];
    L.length--;
    return 1;
}