#include "circular_linked_list.cpp"

void Print_Min(CLinkList &L);

int main()
{
    CLinkList L;
    InitList(L);
    List_TailInsert(L);
    Printlist(L);
    Print_Min(L);
    return 0;
}

void Print_Min(CLinkList &L)
{
    CLNode *p, *pre, *min_pre, *min_p;
    while(L->next != L)
    {
        p = L->next;
        pre = L;
        min_p = p;
        min_pre = pre;
        while(p != L)
        {
            if(p->data < min_p->data)
            {
                min_p = p;
                min_pre = pre;
            }
            pre = p;
            p = p->next;
        }
        std::cout << min_p->data << std::endl;
        min_pre->next = min_p->next;
        delete min_p;
    }
    delete L;
}