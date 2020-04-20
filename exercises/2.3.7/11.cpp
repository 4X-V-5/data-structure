#include "linked_list.cpp"

void Seperate_List(LinkList&C, LinkList &A, LinkList &B);

int main()
{
    LinkList A, B, C;
    InitList(A);
    InitList(B);
    InitList(C);
    List_TailInsert(C);
    Printlist(C);
    Seperate_List(C, A, B);
    Printlist(A);
    Printlist(B);
    return 0;
}

void Seperate_List(LinkList&C, LinkList &A, LinkList &B)
{
    int num = 0;
    LNode *p = C->next;
    LNode *ra = A, *b = B, *temp;
    while(p)
    {
        num++;
        temp = p;
        p = p->next;
        if(num%2 == 0)
        {
            temp->next = b->next;
            b->next = temp;
        }else
        {
            ra->next = temp;
            ra = temp;
            ra->next = NULL;
        }
    }
}