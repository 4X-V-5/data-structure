/*
        将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
*/

#include "sequence_list.cpp"

int MergeList(SeqList a, SeqList b, SeqList &c);

int main()
{
    SeqList a, b, c;
    InitList(a, 10);
    InitList(b, 10);
    InitList(c, 25);
    for(int i=0; i<10; i++)
        a.data[i] = i;
    a.length = 10;
    for(int i=0; i<10; i++)
        b.data[i] = i+10;
    b.length = 10;

    Printlist(a);
    Printlist(b);
    Printlist(c);
    MergeList(a, b, c);
    Printlist(c);
    return 0;
}

int MergeList(SeqList a, SeqList b, SeqList &c)
{
    /*
            算法思想：利用 i 和 j 两个指针依次对比两顺序表的元素，将其中小者放入结果顺序表中。
        若有一表提前遍历完成，则将另一表中的元素直接放入结果顺序表中。
    */

    // 若结果顺序表不能容纳两表中的全部元素，合并失败退出运行
    if(a.length + b.length > c.MaxSize)
        return 0;
    // 指向当前比较元素的指针
    int i = 0, j = 0;
    // 扫描两个表
    while(i<a.length && j<b.length)
    {
        // 将其中小者加入结果顺序表中
        if(a.data[i] <= b.data[j])
        {
            c.data[c.length++] = a.data[i++];
        }else
        {
            c.data[c.length++] = b.data[j++];
        }
    }

    // 若有一表提前遍历完成，则将另一表中的元素直接放入结果顺序表中
    while(i < a.length)
    {
        c.data[c.length++] = a.data[i++];
    }

    while(j < b.length)
    {
        c.data[c.length++] = b.data[j++];
    }
    return 1;

}