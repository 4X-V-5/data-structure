/*
        设将 n (n > 1) 个整数存放到一维数组 R 中。设计一个在时间和空间两方面都尽可
    能高效的算法。将 R 中保存的序列循环左移 p (0 < p < n) 个位置，即将 R 中的数据
    由 (X0, X1, ..., Xn-1) 变换为 (Xp, Xp+1, ..., Xn-1, X0, X1, ..., Xp-1)。
*/

#include <iostream>

void CycleShift(int *L, int n, int p);
void ReverseList(int *L, int a, int b);
void Swap(int &a, int &b);

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    CycleShift(a, 10, 5);
    for(int i=0; i<10; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}

void CycleShift(int *L, int n, int p)
{
    /*
            算法思想：本质上为将表中的子表 (X0, X1, ..., Xp-1) 与 子表 (Xp, Xp+1,
        ..., Xn-1) 位置互换。首先将两个子表进行逆置，即将子表 (X0, X1, ..., Xp-1)
        变换为 (Xp-1, ..., X1, X0)，子表 (Xp, Xp+1, ..., Xn-1) 变换为 (Xn-1, ..., 
        Xp+1, Xp)。再将整个表逆置，即将 (Xp-1, ..., X1, X0, Xn-1, ..., Xp+1, Xp)
        变换为 (Xp, Xp+1, ..., Xn-1, X0, X1, ..., Xp-1)。

    */

    // 将两个子表逆置
    ReverseList(L, 1, p);
    ReverseList(L, p+1, n);
    // 将整个表逆置
    ReverseList(L, 1, n);

}

void ReverseList(int *L, int a, int b)
{
    // 逆置线性表

    a -= 1;
    b -= 1;
    for(; a<b; a++, b--)
    {
        Swap(L[a], L[b]);
    }
}

void Swap(int &a, int &b)
{
    b = a ^ b;
    a = a ^ b;
    b = a ^ b;
}