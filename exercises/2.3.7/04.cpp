#include "linked_list.cpp"

void Delete_Min(LinkList &L);

int main()
{
    LinkList L;
    List_TailInsert(L);
    Printlist(L);
    Delete_Min(L);
    Printlist(L);
    return 0;
}

void Delete_Min(LinkList &L)
{
    LNode *pre = L, *p = L->next;
    LNode *min_pre = pre, *min_p = p;
    while(p)
    {
        if(p->data < min_p->data)
        {
            min_p = p;
            min_pre = pre;
        }
        pre = p;
        p = p->next;
    }
    min_pre->next = min_p->next;
    delete min_p;
    L->data--;
}