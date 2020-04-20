#include "linked_list.cpp"

void Seperate_Odd_Even(LinkList &A, LinkList &B);

int main()
{
    LinkList A, B;
    InitList(A);
    InitList(B);
    List_TailInsert(A);
    Printlist(A);
    Seperate_Odd_Even(A, B);
    Printlist(A);
    Printlist(B);
    return 0;
}

void Seperate_Odd_Even(LinkList &A, LinkList &B)
{
    int num = 0;
    LNode *ra = A, *rb = B;
    LNode *p = A->next;
    A->next = NULL;
    while(p)
    {
        num++;
        if(num%2 == 0)
        {
            rb->next = p;
            rb = rb->next;
        }else
        {
            ra->next = p;
            ra = ra->next;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
}