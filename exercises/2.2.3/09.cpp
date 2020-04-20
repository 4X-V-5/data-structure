#include "sequence_list.cpp"

int FindX(SeqList &L, ElemType x);

int main()
{
    SeqList L;
    InitList(L,15);
    for(int i=0; i<10; i++)
        L.data[i] = i*2;
    L.length = 10;
    Printlist(L);
    FindX(L, 5);
    Printlist(L);
    return 0;
}

int FindX(SeqList &L, ElemType x)
{
    if(L.length == L.MaxSize)
        return 0;

    int low = 0;
    int high = L.length-1;
    int mid;
    while (low<=high)
    {
        mid = (low+high) / 2;
        if(L.data[mid] == x)
        {
            break;
        }else if(L.data[mid] < x)
        {
            low = mid + 1;
        }else
        {
            high = mid - 1;
        }
    }
    
    if(L.data[mid]==x && mid!=L.length-1)
    {
        L.data[mid] = L.data[mid+1];
        L.data[mid+1] = x;
    }

    if(low > high)
    {
        for(int i=L.length-1; i>=mid; i--)
            L.data[i+1] = L.data[i];
        L.data[mid] = x;
        L.length++;
    }
    return 1;
}