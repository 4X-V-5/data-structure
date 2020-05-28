/*
        已知在一维数组 A[m+n] 中依次存放两个线性表 (a1, a2, a3, ..., am) 和
    (b1, b2, b3, ..., bn)。试编写一个函数，将数组中的两个顺序表的位置互换，即将
    (b1, b2, b3, ..., bn) 放在 (a1, a2, a3, ..., am) 的前面。
*/

#include "sequence_list.cpp"

void ReverseList(SeqList &L, int a, int b);
void Reverse(SeqList &L, int m);
void Swap(int &a, int &b);

int main()
{
    SeqList L;
    InitList(L, 15);
    for(int i=0; i<10; i++)
        L.data[i] = i;
    L.length = 10;
    Printlist(L);
    Reverse(L, 5);
    Printlist(L);
    return 0;

}

void Reverse(SeqList &L, int m)
{
    /*
            算法思想：表中的子表 (a1, a2, a3, ..., am) 和 (b1, b2, b3, ..., bn) 逆置，
        即将 (a1, a2, a3, ..., am, b1, b2, b3, ..., bn) 逆置为 (am, ..., a3, a2, a1,
        bn, ..., b3, b2, b1) 。再将整个表逆置，即将 (am, ..., a3, a2, a1, bn, ..., b3,
        b2, b1) 逆置为 (b1, b2, b3, ..., bn, a1, a2, a3, ..., am)。
    */

    // 将两个子表逆置
    ReverseList(L, 1, m);
    ReverseList(L, m+1, L.length);
    // 逆置整个表
    ReverseList(L, 1, L.length);
}

void ReverseList(SeqList &L, int a, int b)
{
    // 逆置线性表 [a, b] 区间逆置
    a -= 1;
    b -= 1;
    int mid = (a+b) / 2;
    for(; a<b; a++, b--)
    {
        Swap(L.data[a], L.data[b]);
    }
}

void Swap(int &a, int &b)
{
    b = a ^ b;
    a = a ^ b;
    b = a ^ b;
}