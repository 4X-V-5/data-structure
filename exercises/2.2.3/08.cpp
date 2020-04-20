#include "sequence_list.cpp"

void ReverseList(SeqList &L, int a, int b);
void Reverse(SeqList &L, int m);

int main()
{
    SeqList L;
    InitList(L, 15);
    for(int i=0; i<10; i++)
        L.data[i] = i;
    L.length = 10;
    Printlist(L);
    Reverse(L, 5);
    Printlist(L);
    return 0;

}

void ReverseList(SeqList &L, int a, int b)
{
    ElemType temp;
    for(int i=a-1; i<b/2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[b-1-i];
        L.data[b-1-i] = temp;
    }
}

void Reverse(SeqList &L, int m)
{
    ReverseList(L, 1, m);
    ReverseList(L, m+1, L.length);
    ReverseList(L, 1, L.length);
}