#include "linked_list.cpp"

int DeleteNodeR(LinkList &L, ElemType x);

int main()
{
    LinkList L;
    List_HeadInsert(L);
    Printlist(L);
    DeleteNodeR(L, 3);
    Printlist(L);
    return 0;
}

int DeleteNodeR(LinkList &L, ElemType x)
{
    LNode *p;
    if(!L)
        return 0;
    if(L->data == x)
    {
        p = L;
        L = L->next;
        delete p;
        DeleteNodeR(L, x);
    }else
    {
        DeleteNodeR(L->next, x);
    }
    return 1;
}