/*
        从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个
    元素填补，若顺序表为空则显示出错信息并退出运行。
*/

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
    /*
            算法思想：扫描一遍顺序表，保存最小值元素的下标。用 e 返回最小值元素的值
        后将最小值与表尾元素互换，最后将表长减1.
    */

    // 若为空表，删除失败退出运行
    if(L.length == 0)
    {
        std::cout << "Error: list is empty.\n";
        return 0;
    }
        
    // position 存储最小值元素下标
    int position = 0;
    e = L.data[0];
    // 扫描整个表
    for(int i=1; i<L.length; i++)
    {
        // 若目前元素比当前最小值还小，则更新最小值元素的位置
        if(L.data[i] < e)
        {
            // e 存储最小元素的值
            e = L.data[i];
            position = i;
        }
    }
    // 互换最小值元素与表尾元素
    L.data[position] = L.data[L.length-1];
    // 表长减1
    L.length--;
    return 1;
}