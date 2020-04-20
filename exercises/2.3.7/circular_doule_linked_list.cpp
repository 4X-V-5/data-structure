#include <iostream>
#define ElemType int

// Strcuture declaration
typedef struct CDLNode
{
    ElemType data;
    struct CDLNode *prior, *next;
}CDLNode, *CDLinkList;

// Basic operations
void InitList(CDLinkList &L);                           // Modify header node for linked list
int Length(CDLinkList L);                              // Return the length of given linked list
CDLNode *LocateElem(CDLinkList L, ElemType e);           // Return the first position with given value
CDLNode *GetElem(CDLinkList L, int p);                   // Return value in given position
CDLinkList List_HeadInsert(CDLinkList &L);               // Create Linked list using head insert
CDLinkList List_TailInsert(CDLinkList &L);               // Create Linked list using tail insert
int ListInsert(CDLinkList &L, int p, ElemType e);      // Insert element e to given position
int ListDelete(CDLinkList &L, int p, ElemType &e);     // Delete element in given opsition and return it to e
void Printlist(CDLinkList L);                          // Print linked list
int Empty(CDLinkList L);                               // To judge if the list is empty
void DestroyList(CDLinkList &L);                       // Destroy given list and release space


void InitList(CDLinkList &L)
{
    // Modify header node for linked list
    // Header node stores current length of the linked list
    L = new CDLNode;
    L->data = 0;
    L->next = L;
    L->prior = L;
}

int Length(CDLinkList L)
{
    // Return the length of given linked list
    int count = 0;
    CDLNode *p = L->next;
    while(p != L)
    {
        count++;
        p = p->next;
    }
    return count;
}

CDLNode *LocateElem(CDLinkList L, ElemType e)
{
    // Return the first position with given value
    CDLNode *p = L->next;
    while(p!=L && p->data != e)
        p = p->next;

    return p;
}

CDLNode *GetElem(CDLinkList L, int p)
{
    // Return value in given position
    CDLNode *n = L;
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

CDLinkList List_HeadInsert(CDLinkList &L)
{
    // Create Linked list using head insert
    CDLNode *p;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new CDLNode;
        p->data = x;
        p->next = L->next;
        L->next->prior = p;
        L->next = p;
        p->prior = L;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    return L;
}

CDLinkList List_TailInsert(CDLinkList &L)
{
    // Create Linked list using tail insert
    CDLNode *p, *tail = L;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new CDLNode;
        p->data = x;
        tail->next = p;
        p->next = L;
        L->prior = p;
        p->prior = tail;
        tail = p;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    return L;
}

int ListInsert(CDLinkList &L, int p, ElemType e)
{
    // Insert element e to given position
    if(p > Length(L)+1)
        return 0;
    CDLNode *pre = L;
    CDLNode *newNode = new CDLNode;
    newNode->data = e;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    newNode->next = pre->next;
    pre->next->prior = newNode;
    pre->next = newNode;
    newNode->prior = pre;
    return 1;
}

int ListDelete(CDLinkList &L, int p, ElemType &e)
{
    // Delete element in given opsition and return it to e
    if(p > Length(L))
        return 0;
    CDLNode *pre = L;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    CDLNode *deCDLNode = pre->next;
    e = deCDLNode->data;
    pre->next = deCDLNode->next;
    deCDLNode->next->prior = pre;
    delete deCDLNode;
    return 1;
}

void Printlist(CDLinkList L)
{
    // Print linked list
    CDLNode *p = L->next;
    while(p != L)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int Empty(CDLinkList L)
{
    return L->next==L && L->prior==L;
}

void DestroyList(CDLinkList &L)
{
    // Destroy given list and release space
    CDLNode *p = L->next, *q;
    L->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        delete q;
    }
}