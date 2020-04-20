#include "linked_list.cpp"

LinkList Common_Node_List(LinkList A, LinkList B);

int main()
{
    LinkList A, B, C;
    InitList(A);
    InitList(B);
    List_TailInsert(A);
    List_TailInsert(B);
    Printlist(A);
    Printlist(B);
    C = Common_Node_List(A, B);
    Printlist(C);
    return 0;
}

LinkList Common_Node_List(LinkList A, LinkList B)
{
    LinkList C = new LNode;
    C->next = NULL;
    LNode *p = A->next, *q = B->next, *r = C, *n;
    while(p&&q)
    {
        if(p->data < q->data)
        {
            p = p->next;
        }else if(q->data < p->data)
        {
            q = q->next;
        }else
        {
            n = new LNode;
            n->data = p->data;
            r->next = n;
            r = r->next;
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return C;
}