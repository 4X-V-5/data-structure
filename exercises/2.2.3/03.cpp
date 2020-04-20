#include "sequence_list.cpp"

void DeleteX(SeqList &L, ElemType x);

int main()
{
    ElemType temp;
    SeqList L;
    InitList(L, 10);
    for(int i=1; i<6; i++)
        ListInsert(L, i, i%3);
    Printlist(L);
    DeleteX(L, 1);
    Printlist(L);
    return 0;

}

void DeleteX(SeqList &L, ElemType x)
{
    int count = 0;
    for(int i=0; i<L.length; i++)
    {
        if(L.data[i] == x)
        {
            count++;
        } else
        {
            L.data[i-count] = L.data[i];
        }
    }
    L.length -= count;
}