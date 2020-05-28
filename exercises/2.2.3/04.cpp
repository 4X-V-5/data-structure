/*
        从有序顺序表中删除其值在给定值 s 与 t 之间（要求 s < t）的所有元素，如果 s 或 t 不合理
    或顺序表为空，则显示出错信息并退出运行。
*/

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
    /*
            算法思想：用 count 统计 s 与 t 之间元素个数，将 t 之后的元素统一向前移动 count 位。
        最后修改表长。
    */

    // 若 s 与 t 不合理或顺序表为空，打印出错信息并退出运行
    if(s>t || L.length==0)
    {
        std::cout << "Error: s > t or list is empty.\n";
        return 0;
    }
        
    int count = 0;
    ElemType temp;

    // 扫描顺序表
    for(int i=0; i<L.length; i++)
    {
        // 统计 s 与 t 之间的元素个数
        if(L.data[i]>s && L.data[i]<t)
        {
            count++;
        }
        // 扫描到 t 之后的元素时将元素向前移动 count 位
        else if(i > t)
        {
            L.data[i-count] = L.data[i];
        }
    }
    // 修改表长
    L.length -= count;
    return 1;
}