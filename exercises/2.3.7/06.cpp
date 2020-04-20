#include "linked_list.cpp"

void Sort(LinkList &L);

int main()
{
    LinkList L;
    List_TailInsert(L);
    Printlist(L);
    Sort(L);
    Printlist(L);
    return 0;
}

void Sort(LinkList &L)
{
    LNode *p = L->next->next, *pre; // p = next node for comparison
    LNode *r;
    L->next->next = NULL; // Construct result
    while(p)
    {
        r = p->next; // r = node for next round comparison
        pre = L; // Iterate the whole list
        while(pre->next && pre->next->data < p->data)
            pre = pre->next; // Find insert position
        // Insertion
        p->next = pre->next;
        pre->next = p;
        // Next node for comparison
        p = r;
    }
}