#include <iostream>
#define ElemType int

// Strcuture declaration
typedef struct CLNode
{
    ElemType data;
    struct CLNode *next;
}CLNode, *CLinkList;

// Basic operations
void InitList(CLinkList &L);                           // Modify header node for linked list
int Length(CLinkList L);                              // Return the length of given linked list
CLNode *LocateElem(CLinkList L, ElemType e);           // Return the first position with given value
CLNode *GetElem(CLinkList L, int p);                   // Return value in given position
CLinkList List_HeadInsert(CLinkList &L);               // Create Linked list using head insert
CLinkList List_TailInsert(CLinkList &L);               // Create Linked list using tail insert
int ListInsert(CLinkList &L, int p, ElemType e);      // Insert element e to given position
int ListDelete(CLinkList &L, int p, ElemType &e);     // Delete element in given opsition and return it to e
void Printlist(CLinkList L);                          // Print linked list
int Empty(CLinkList L);                               // To judge if the list is empty
void DestroyList(CLinkList &L);                       // Destroy given list and release space

int main()
{
    int temp = 0;
    CLinkList L;
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


void InitList(CLinkList &L)
{
    // Modify header node for linked list
    // Header node stores current length of the linked list
    L = new CLNode;
    L->data = 0;
    L->next = L;
}

int Length(CLinkList L)
{
    // Return the length of given linked list
    int count = 0;
    CLNode *p = L->next;
    while(p != L)
    {
        count++;
        p = p->next;
    }
    return count;
}

CLNode *LocateElem(CLinkList L, ElemType e)
{
    // Return the first position with given value
    CLNode *p = L->next;
    while(p!=L && p->data != e)
        p = p->next;

    return p;
}

CLNode *GetElem(CLinkList L, int p)
{
    // Return value in given position
    CLNode *n = L;
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

CLinkList List_HeadInsert(CLinkList &L)
{
    // Create Linked list using head insert
    CLNode *p;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new CLNode;
        p->data = x;
        p->next = L->next;
        L->next = p;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    return L;
}

CLinkList List_TailInsert(CLinkList &L)
{
    // Create Linked list using tail insert
    CLNode *p, *tail = L;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new CLNode;
        p->next = L;
        p->data = x;
        tail->next = p;
        tail = p;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    return L;
}

int ListInsert(CLinkList &L, int p, ElemType e)
{
    // Insert element e to given position
    if(p > Length(L)+1)
        return 0;
    CLNode *pre = L;
    CLNode *newNode = new CLNode;
    newNode->data = e;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    newNode->next = pre->next;
    pre->next = newNode;
    return 1;
}

int ListDelete(CLinkList &L, int p, ElemType &e)
{
    // Delete element in given opsition and return it to e
    if(p > Length(L))
        return 0;
    CLNode *pre = L;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    CLNode *deCLNode = pre->next;
    e = deCLNode->data;
    pre->next = deCLNode->next;
    delete deCLNode;
    return 1;
}

void Printlist(CLinkList L)
{
    // Print linked list
    CLNode *p = L->next;
    while(p != L)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int Empty(CLinkList L)
{
    return !(L->next==L);
}

void DestroyList(CLinkList &L)
{
    // Destroy given list and release space
    CLNode *p = L->next, *q;
    L->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
        delete q;
    }
}