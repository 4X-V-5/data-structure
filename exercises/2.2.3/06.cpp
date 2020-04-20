#include "sequence_list.cpp"

void RemoveDuplicate(SeqList &L);

int main()
{
    ElemType temp;
    SeqList L;
    InitList(L, 10);
    L.data[0] = 1;
    L.data[1] = 1;
    L.data[2] = 2;
    L.data[3] = 3;
    L.data[4] = 3;
    L.data[5] = 3;
    L.data[6] = 4;
    L.length = 7;
    Printlist(L);
    RemoveDuplicate(L);
    Printlist(L);
    return 0;

}

void RemoveDuplicate(SeqList &L)
{
    int count = 0;
    ElemType repeat = L.data[0];
    for(int i=1; i<L.length; i++)
    {
        if(L.data[i] == repeat)
        {
            count++;
        } else
        {
            repeat = L.data[i];
            L.data[i-count] = L.data[i];
        }   
    }
    L.length -= count;
}