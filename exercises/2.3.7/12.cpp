#include "linked_list.cpp"

void Delete_Dupliacte(LinkList &L);

int main()
{
    LinkList L;
    InitList(L);
    List_TailInsert(L);
    Printlist(L);
    Delete_Dupliacte(L);
    Printlist(L);
    return 0;
}

void Delete_Dupliacte(LinkList &L)
{
    if(Length(L) < 2)
        return;
    ElemType curr = L->next->data;
    LNode *pre = L->next, *p = L->next->next, *d;
    while(p)
    {
        if(p->data == curr)
        {
            d = p;
            p = p->next;
            pre->next = p;
            delete d;
        }else
        {
            curr = p->data;
            pre = p;
            p = p->next;
        }
        
    }
}