#include "circular_doule_linked_list.cpp"
#include <iostream>

int Symmetric(CDLinkList L);

int main()
{
    CDLinkList L;
    InitList(L);
    List_TailInsert(L);
    Printlist(L);
    std::cout << Symmetric(L) << std::endl;
    return 0;
}

int Symmetric(CDLinkList L)
{
    CDLNode *p = L->next, *q = L->prior;
    while(p!=q && q->next!=p)
    {
        if(p->data != q->data)
            return 0;
        p = p->next;
        q = q->prior;
    }
    return 1;
}