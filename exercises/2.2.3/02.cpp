/*
        设计一个高效算法，将顺序表 L 的所有元素逆置，要求算法的空间复杂度为 O(1)。
*/

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
    /*
            算法思想：将表的首尾相应的元素对调，直至遇到中间元素。
    */
   
    ElemType temp;
    // 从表头元素扫描至中间元素，若表长为奇数，则中间元素不参与互换
    for(int i=0; i<L.length/2; i++)
    {
        // 互换首尾相应的元素
        temp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = temp;
    }
}