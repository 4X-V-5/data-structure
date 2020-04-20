#include "sequence_list.cpp"

int DelFromList(SeqList &L, ElemType s, ElemType t);

int main()
{
    ElemType temp;
    SeqList L;
    InitList(L, 10);
    L.data[0] = 2;
    L.data[1] = 7;
    L.data[2] = 4;
    L.data[3] = 8;
    L.data[4] = 10;
    L.data[5] = 9;
    L.data[6] = 3;
    L.length = 7;
    Printlist(L);
    DelFromList(L, 2, 8);
    Printlist(L);
    return 0;

}

int DelFromList(SeqList &L, ElemType s, ElemType t)
{
    if(s>t || L.length==0)
        return 0;
    int count = 0;
    ElemType temp;
    for(int i=0; i<L.length; i++)
    {
        if(L.data[i]>=s && L.data[i]<=t)
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