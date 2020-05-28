/*
        从有序顺序表表中删除所有其值重复的元素，使表中所有元素的值均不同。
*/

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
    /*
            算法思想：用 count 记录重复元素的个数，repeat 记录当前检查重复的元素值。扫描一遍顺序表，
        若当前元素值等于当前检查重复的元素值，说明有元素重复，count 值加1；若不相同，则代表当前检查重
        复的元素已扫描完毕，将当前检查的值更新为当前元素值，并前移填补空缺。最后修改表长。
    */

    // 记录重复元素的个数
    int count = 0;
    // 记录当前检查重复的元素值
    ElemType repeat = L.data[0];
    // 扫描顺序表
    for(int i=1; i<L.length; i++)
    {
        // 如果重复，count 值加1
        if(L.data[i] == repeat)
        {
            count++;
        }
        // 如果没有重复，更新当前检查元素的值，并前移填补空缺
        else
        {
            repeat = L.data[i];
            L.data[i-count] = L.data[i];
        }   
    }
    // 修改表长
    L.length -= count;
}