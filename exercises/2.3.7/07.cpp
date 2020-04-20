#include "linked_list.cpp"

void Delete_interval(LinkList &L, ElemType a, ElemType b);

int main()
{
    LinkList L;
    List_TailInsert(L);
    Printlist(L);
    Delete_interval(L, 3, 7);
    Printlist(L);
    return 0;
}

void Delete_interval(LinkList &L, ElemType a, ElemType b)
{
    LNode *pre = L, *p = L->next, *d;
    while(p)
    {
        if(p->data>a && p->data<b)
        {
            d = p;
            pre->next = p->next;
            p = p->next;
            delete d;
            continue;
        }
        pre = p;
        p = p->next;
    }
}