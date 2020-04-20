#include "linked_list.cpp"

LinkList Merge_Sorted(LinkList &A, LinkList &B);

int main()
{
    LinkList A, B;
    InitList(A);
    InitList(B);
    List_TailInsert(A);
    List_TailInsert(B);
    Printlist(A);
    Printlist(B);
    LinkList C = Merge_Sorted(A, B);
    Printlist(C);
    return 0;
}

LinkList Merge_Sorted(LinkList &A, LinkList &B)
{
    LinkList C = new LNode;
    C->next = NULL;
    LNode *p = A->next, *q = B->next, *n;
    while(p&&q)
    {
        if(p->data > q->data)
        {
            n = p;
            p = p->next;
            n->next = C->next;
            C->next = n;
        }else
        {
            n = q;
            q = q->next;
            n->next = C->next;
            C->next = n;
        }
    }
    while(p)
    {
        n = p;
        p = p->next;
        n->next = C->next;
        C->next = n;
    }
    while(q)
    {
        n = q;
        q = q->next;
        n->next = C->next;
        C->next = n;
    }
    return C;
}