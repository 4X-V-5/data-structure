/*
        对长度为 n 的顺序表 L ，编写一个时间复杂度为 O(n) ，空间复杂度为 O(1) 的算法，该算法删除线性表中
    所有值为 x 的数据元素。
*/

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
    /*
            算法思想：用 count 统计所有值为 x 的数据元素，从前往后扫描顺序表，若当前元素值为 x ，count 值加1；
        若当前元素值不为 x ，则前面删除了几个值为 x 的数据元素， 当前元素的位置就往前移动几位。最后修改表长。
    */

    int count = 0;
    // 扫描顺序表
    for(int i=0; i<L.length; i++)
    {
        // 若值为 x ，count 加1
        if(L.data[i] == x)
        {
            count++;
        } else
        {
            // 往前移动
            L.data[i-count] = L.data[i];
        }
    }
    // 修改表长
    L.length -= count;
}