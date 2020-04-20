#include "circular_linked_list.cpp"

void Merge_Circular(CLinkList &h1, CLinkList &h2);

int main()
{
    CLinkList h1, h2;
    InitList(h1);
    InitList(h2);
    List_TailInsert(h1);
    List_TailInsert(h2);
    Printlist(h1);
    Printlist(h2);
    Merge_Circular(h1, h2);
    Printlist(h1);
    return 0;
}

void Merge_Circular(CLinkList &h1, CLinkList &h2)
{
    CLNode *p = h1->next, *h = h2;
    while(p->next != h1)
        p = p->next;
    p->next = h->next;
    while(p->next != h2)
        p = p->next;
    p->next = h1;
    delete h2;
}