#include <iostream>
#define ElemType int

// Strcuture declaration
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

// Basic operations
void InitList(LinkList &L);                           // Modify header node for linked list
int Length(LinkList L);                              // Return the length of given linked list
LNode *LocateElem(LinkList L, ElemType e);           // Return the first position with given value
LNode *GetElem(LinkList L, int p);                   // Return value in given position
LinkList List_HeadInsert(LinkList &L);               // Create Linked list using head insert
LinkList List_TailInsert(LinkList &L);               // Create Linked list using tail insert
int ListInsert(LinkList &L, int p, ElemType e);      // Insert element e to given position
int ListDelete(LinkList &L, int p, ElemType &e);     // Delete element in given opsition and return it to e
void Printlist(LinkList L);                          // Print linked list
int Empty(LinkList L);                               // To judge if the list is empty
void DestroyList(LinkList &L);                       // Destroy given list and release space


void InitList(LinkList &L)
{
    // Modify header node for linked list
    // Header node stores current length of the linked list
    L = new LNode;
    L->data = 0;
    L->next = NULL;
}

int Length(LinkList L)
{
    // Return the length of given linked list
    int count = 0;
    LNode *p = L->next;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

LNode *LocateElem(LinkList L, ElemType e)
{
    // Return the first position with given value
    LNode *p = L->next;
    while(p && p->data != e)
        p = p->next;

    return p;
}

LNode *GetElem(LinkList L, int p)
{
    // Return value in given position
    LNode *n = L;
    if(p == 0)
        return L;
    if(p < 1)
        return NULL;
    for(int i=0; i<p; i++)
    {
        n = n->next;
    }
    return n;
}

LinkList List_HeadInsert(LinkList &L)
{
    // Create Linked list using head insert
    LNode *p;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new LNode;
        p->data = x;
        p->next = L->next;
        L->next = p;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    return L;
}

LinkList List_TailInsert(LinkList &L)
{
    // Create Linked list using tail insert
    LNode *p, *tail = L;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new LNode;
        p->next = NULL;
        p->data = x;
        tail->next = p;
        tail = p;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    return L;
}

int ListInsert(LinkList &L, int p, ElemType e)
{
    // Insert element e to given position
    if(p > L->data+1)
        return 0;
    LNode *pre = L;
    LNode *newNode = new LNode;
    newNode->data = e;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    newNode->next = pre->next;
    pre->next = newNode;
    return 1;
}

int ListDelete(LinkList &L, int p, ElemType &e)
{
    // Delete element in given opsition and return it to e
    if(p > L->data)
        return 0;
    LNode *pre = L;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    LNode *delNode = pre->next;
    e = delNode->data;
    pre->next = delNode->next;
    delete delNode;
    return 1;
}

void Printlist(LinkList L)
{
    // Print linked list
    LNode *p = L->next;
    while(p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int Empty(LinkList L)
{
    return !L->next;
}

void DestroyList(LinkList &L)
{
    // Destroy given list and release space
    LNode *p;
    while(L)
    {
        p = L->next;
        delete L;
        L = p;
    }
}