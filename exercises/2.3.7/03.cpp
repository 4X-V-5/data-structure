#include <iostream>
#include "linked_list.cpp"

void Reverse_Print(LinkList L);

int main()
{
    LinkList L;
    List_TailInsert(L);
    Printlist(L);
    Reverse_Print(L->next);
    std::cout << std::endl;
    return 0;
}

void Reverse_Print(LinkList L)
{
    if(L->next)
        Reverse_Print(L->next);
    if(L)
        std::cout << L->data << " ";
}