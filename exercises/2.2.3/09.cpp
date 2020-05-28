/*
        线性表 (a1, a2, a3, ..., an) 中的元素递增有序且按顺序存储于计算机内。要求设计一算法，
    完成用最少时间在表中查找数值为 x 的元素，若找到则将其与后继元素位置相交换，若找不到则将其插入
    表中并使表中元素仍递增有序。
*/

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
    /*
            算法思想：利用二分查找查找元素所在位置，若查找成功，mid 则指向要查找的元素的位置；若查找失败
        low 指针指向元素应当被插入的位置，将其插入即可。
    */

    // 二分查找
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
    
    // 若查找成功且有后继元素，则将其与后继元素互换
    if(L.data[mid]==x && mid!=L.length-1)
    {
        L.data[mid] = L.data[mid+1];
        L.data[mid+1] = x;
    }

    // 若查找失败
    if(low > high)
    {
        // 若表已满，则插入失败退出运行
        if(L.length == L.MaxSize)
            return 0;
        // 插入元素
        for(int i=L.length-1; i>=mid; i--)
            L.data[i+1] = L.data[i];
        L.data[mid] = x;
        L.length++;
    }
    return 1;
}