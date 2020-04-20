#include <iostream>
#define ElemType int

typedef struct DLNode
{
    ElemType data;
    struct DLNode *pred, *next;
    int freq;
}DLNode, *DLinkList;

DLNode *Locate(DLinkList &L, ElemType x);

DLNode *Locate(DLinkList &L, ElemType x)
{
    DLNode *p = L->next, *q;
    while(p && p->data!=x)
        p = p->next;

    if(!p)
        return NULL;

    p->freq++;
    if(p->next != NULL)
        p->next->pred = p->pred;
    p->pred->next = p->next;
    q = p->pred;
    while(q!=L && q->freq<=p->freq)
        q = q->pred;
    p->next = q->next;
    q->next->pred = p;
    q->next = p;
    p->pred = q;
    return p;
    
}