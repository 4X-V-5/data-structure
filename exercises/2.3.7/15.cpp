#include "linked_list.cpp"

void Union(LinkList &A, LinkList &B);

int main()
{
    LinkList A, B;
    InitList(A);
    InitList(B);
    List_TailInsert(A);
    List_TailInsert(B);
    Printlist(A);
    Printlist(B);
    Union(A, B);
    Printlist(A);
    return 0;
}

void Union(LinkList &A, LinkList &B)
{
    LNode *p = A->next, *q = B->next;
    LNode *r = A, *d;
    A->next = NULL;
    while(p&&q)
    {
        if(p->data < q->data)
        {
            d = p;
            p = p->next;
        }else if(q->data < p->data)
        {
            d = q;
            q = q->next;
        }else
        {
            r->next = p;
            r = r->next;
            d = q;
            p = p->next;
            q = q->next;
        }
        delete d;
    }
    r->next = NULL;
    while(p)
    {
        d = p;
        p = p->next;
        delete d;
    }
    while(q)
    {
        d = q;
        q = q->next;
        delete d;
    }
    delete B;
}