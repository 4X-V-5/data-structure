#include "linked_list.cpp"
#include <iostream>

LNode *Find_First_Common_Node(LinkList L1, LinkList L2);

int main()
{
    LinkList L1, L2, common;
    InitList(L1);
    InitList(L2);
    InitList(common);
    List_TailInsert(L1);
    List_TailInsert(L2);
    List_TailInsert(common);
    common->data = 4567;
    LNode *p=L1->next, *q =L2->next;
    while(p->next)
        p = p->next;
    while(q->next)
        q = q->next;
    p->next = common;
    q->next = common;
    LNode *common_node = Find_First_Common_Node(L1, L2);
    std::cout << common_node->data << std::endl;
    return 0;
}

LNode *Find_First_Common_Node(LinkList L1, LinkList L2)
{
    int len1 = Length(L1);
    int len2 = Length(L2);
    LNode *p = L1->next, *q = L2->next;
    if(len1 > len2)
    {
        for(int i=0; i<len1-len2; i++)
            p = p->next;
    }else
    {
        for(int i=0; i<len2-len1; i++)
            q = q->next;
    }
    while(p)
    {
        if(p==q)
            return p;
        p = p->next;
        q = q->next;
    }
    
    return NULL;
}