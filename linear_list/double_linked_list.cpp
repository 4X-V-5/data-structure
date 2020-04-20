#include <iostream>
#define ElemType int

// Strcuture declaration
typedef struct DLNode
{
    ElemType data;
    struct DLNode *prior, *next;
}DLNode, *DLinkList;

// Basic operations
void InitList(DLinkList &L);                           // Modify header node for linked list
int Length(DLinkList L);                              // Return the length of given linked list
DLNode *LocateElem(DLinkList L, ElemType e);           // Return the first position with given value
DLNode *GetElem(DLinkList L, int p);                   // Return value in given position
DLinkList List_HeadInsert(DLinkList &L);               // Create Linked list using head insert
DLinkList List_TailInsert(DLinkList &L);               // Create Linked list using tail insert
int ListInsert(DLinkList &L, int p, ElemType e);      // Insert element e to given position
int ListDelete(DLinkList &L, int p, ElemType &e);     // Delete element in given opsition and return it to e
void Printlist(DLinkList L);                          // Print linked list
int Empty(DLinkList L);                               // To judge if the list is empty
void DestroyList(DLinkList &L);                       // Destroy given list and release space

int main()
{
    int temp = 0;
    DLinkList L;
    InitList(L);
    std::cout << "length after initialization:" << Length(L) << "\n";
    std::cout << "empty:" << Empty(L) << "\n";
    List_TailInsert(L);
    Printlist(L);
    std::cout << Length(L) << "\n";
    std::cout << ListInsert(L, 5, 5) << "\n";
    Printlist(L);
    std::cout << ListDelete(L, 2, temp) << "\n";
    std::cout << temp << "\n";
    Printlist(L);
    std::cout << Length(L) << "\n";
    DestroyList(L);
    return 0;
}


void InitList(DLinkList &L)
{
    // Modify header node for linked list
    // Header node stores current length of the linked list
    L = new DLNode;
    L->data = 0;
    L->next = NULL;
    L->prior = NULL;
}

int Length(DLinkList L)
{
    // Return the length of given linked list
    int count = 0;
    DLNode *p = L->next;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

DLNode *LocateElem(DLinkList L, ElemType e)
{
    // Return the first position with given value
    DLNode *p = L->next;
    while(p && p->data != e)
        p = p->next;

    return p;
}

DLNode *GetElem(DLinkList L, int p)
{
    // Return value in given position
    DLNode *n = L;
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

DLinkList List_HeadInsert(DLinkList &L)
{
    // Create Linked list using head insert
    DLNode *p;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new DLNode;
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

DLinkList List_TailInsert(DLinkList &L)
{
    // Create Linked list using tail insert
    DLNode *p, *tail = L;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new DLNode;
        p->data = x;
        tail->next = p;
        p->next = NULL;
        p->prior = tail;
        tail = p;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    return L;
}

int ListInsert(DLinkList &L, int p, ElemType e)
{
    // Insert element e to given position
    if(p > Length(L)+1)
        return 0;
    DLNode *pre = L;
    DLNode *newNode = new DLNode;
    newNode->data = e;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    newNode->next = pre->next;
    pre->next->prior = newNode;
    pre->next = newNode;
    newNode->prior = pre;
    return 1;
}

int ListDelete(DLinkList &L, int p, ElemType &e)
{
    // Delete element in given opsition and return it to e
    if(p > Length(L))
        return 0;
    DLNode *pre = L;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    DLNode *deDLNode = pre->next;
    e = deDLNode->data;
    pre->next = deDLNode->next;
    deDLNode->next->prior = pre;
    delete deDLNode;
    return 1;
}

void Printlist(DLinkList L)
{
    // Print linked list
    DLNode *p = L->next;
    while(p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int Empty(DLinkList L)
{
    return !L->next;
}

void DestroyList(DLinkList &L)
{
    // Destroy given list and release space
    DLNode *p;
    while(L)
    {
        p = L->next;
        delete L;
        L = p;
    }
}