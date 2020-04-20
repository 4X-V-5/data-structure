#include "linked_list.cpp"

LinkList Reverse_List(LinkList L);

int main()
{
    LinkList L;
    List_TailInsert(L);
    Printlist(L);
    LinkList L2 = Reverse_List(L);
    Printlist(L2);
    return 0;
}

LinkList Reverse_List(LinkList L)
{
    LNode *p = L->next, *q;
    L->next = NULL;
    while(p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return L;
}