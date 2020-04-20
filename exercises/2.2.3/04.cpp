#include "sequence_list.cpp"

int DelFromOrderedList(SeqList &L, ElemType s, ElemType t);

int main()
{
    ElemType temp;
    SeqList L;
    InitList(L, 10);
    for(int i=1; i<6; i++)
        ListInsert(L, i, i);
    Printlist(L);
    DelFromOrderedList(L, 1, 5);
    Printlist(L);
    return 0;

}

int DelFromOrderedList(SeqList &L, ElemType s, ElemType t)
{
    if(s>t || L.length==0)
        return 0;
    int count = 0;
    ElemType temp;
    for(int i=0; i<L.length; i++)
    {
        if(L.data[i]>s && L.data[i]<t)
        {
            count++;
        } else
        {
            L.data[i-count] = L.data[i];
        }
    }
    L.length -= count;
    return 1;
}