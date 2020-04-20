#include "linked_list.cpp"
#include <iostream>

void Print_Ordered(LinkList &L);

int main()
{
    LinkList L;
    InitList(L);
    List_TailInsert(L);
    Printlist(L);
    Print_Ordered(L);
    return 0;
}

void Print_Ordered(LinkList &L)
{
    LNode *pre, *p, *d;
    while(L->next)
    {
        pre = L;
        p = pre->next;
        while(p->next)
        {
            if(p->next->data < pre->next->data)
                pre = p;
            p = p->next;
        }
        std::cout << pre->next->data << " ";
        d = pre->next;
        pre->next = d->next;
        delete d;
    }
    std::cout << std::endl;
    delete L;   
}