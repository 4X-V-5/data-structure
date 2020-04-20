#include "linked_list.cpp"
#include <iostream>

int Pattern(LinkList A, LinkList B);

int main()
{
    LinkList A, B;
    InitList(A);
    InitList(B);
    List_TailInsert(A);
    List_TailInsert(B);
    Printlist(A);
    Printlist(B);
    std::cout << Pattern(A, B) << std::endl;
    return 0;
}

int Pattern(LinkList A, LinkList B)
{
    LNode *start = B->next;
    LNode *p = A->next, *q = B->next;
    while(p&&q)
    {
        if(p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }else
        {
            p = p->next;
            q = start;
        }
    }
    if(!q)
    {
        return 1;
    }else
    {
        return 0;
    }
    
}