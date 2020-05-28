/*
        从顺序表中删除其值在给定值 s 与 t 之间（包含 s 和 t ，要求 s < t）的所有元素，如果 s 或 t 不合理
    或顺序表为空，则显示出错信息并退出运行。
*/

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
    /*
            算法思想：利用 count 统计位于区间 [s, t] 的元素个数。扫描一遍顺序表，若当前元素值位于区间 [s, t]，
        count 值加1；若为其他元素，则将其前移，前移位数为 count 的值。最后修改表长。
    */

    // 若 s 与 t 不合理或顺序表为空，打印出错信息并退出运行
    if(s>t || L.length==0)
        return 0;
    // 统计位于区间 [s, t] 的元素个数
    int count = 0;
    ElemType temp;
    // 扫描顺序表
    for(int i=0; i<L.length; i++)
    {
        // 若当前元素值位于区间 [s, t]，count 值加1
        if(L.data[i]>=s && L.data[i]<=t)
        {
            count++;
        }
        // 若为其他元素，则将其前移，前移位数为 count 的值
        else
        {
            L.data[i-count] = L.data[i];
        }
    }
    // 修改表长
    L.length -= count;
    return 1;
}