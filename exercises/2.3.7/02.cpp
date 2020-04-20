#include "linked_list.cpp"

int DeleteNode(LinkList &L, ElemType x);

int main()
{
    LinkList L;
    List_TailInsert(L);
    Printlist(L);
    DeleteNode(L, 4);
    Printlist(L);
    return 0;
}

int DeleteNode(LinkList &L, ElemType x)
{
    if(!L->next)
        return 0;
    LNode *d, *pre = L, *p = L->next;
    while(p)
    {
        if(p->data == x)
        {
            d = p;
            p = p->next;
            pre->next = p;
            delete d;
        }else
        {
            pre = p;
            p = p->next;
        }
        
    }
    return 1;
}