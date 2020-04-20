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
LNode *LocateElem(LinkList L, ElemType e);           // Return the first node with given value
LNode *GetElem(LinkList L, int p);                   // Return node in given position
LinkList List_HeadInsert(LinkList &L);               // Create Linked list using head insert
LinkList List_TailInsert(LinkList &L);               // Create Linked list using tail insert
int ListInsert(LinkList &L, int p, ElemType e);      // Insert element e to given position
int ListDelete(LinkList &L, int p, ElemType &e);     // Delete element in given opsition and return it to e
void Printlist(LinkList L);                          // Print linked list
int Empty(LinkList L);                               // To judge if the list is empty
void DestroyList(LinkList &L);                       // Destroy given list and release space

int main()
{
    int temp = 0;
    LinkList L;
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


void InitList(LinkList &L)
{
    // Modify header node for linked list
    // Header node stores current length of the linked list
    L = NULL;
}

int Length(LinkList L)
{
    // Return the length of given linked list
    int count = 0;
    LNode *p = L;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

LNode *LocateElem(LinkList L, ElemType e)
{
    // Return the first node with given value
    LNode *p = L;
    while(p && p->data != e)
        p = p->next;

    return p;
}

LNode *GetElem(LinkList L, int p)
{
    // Return node in given position
    LNode *n = L;
    if(p < 1)
        return NULL;
    for(int i=1; i<p; i++)
    {
        n = n->next;
    }
    return n;
}

LinkList List_HeadInsert(LinkList &L)
{
    // Create Linked list using head insert
    LNode *dummy = new LNode;
    dummy->next = L;
    LNode *p;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new LNode;
        p->data = x;
        p->next = dummy->next;
        dummy->next = p;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    L = dummy->next;
    delete dummy;
    return L;
}

LinkList List_TailInsert(LinkList &L)
{
    // Create Linked list using head insert
    LNode *dummy = new LNode, *r = dummy;
    dummy->next = L;
    LNode *p;
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        p = new LNode;
        p->data = x;
        p->next = NULL;
        r->next = p;
        r = r->next;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    L = dummy->next;
    delete dummy;
    return L;
}

int ListInsert(LinkList &L, int p, ElemType e)
{
    // Insert element e to given position
    if(p > Length(L)+1)
        return 0;
    LNode *dummy = new LNode;
    dummy->next = L;
    LNode *pre = dummy;
    LNode *newNode = new LNode;
    newNode->data = e;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    newNode->next = pre->next;
    pre->next = newNode;
    L = dummy->next;
    delete dummy;
    return 1;
}

int ListDelete(LinkList &L, int p, ElemType &e)
{
    // Delete element in given opsition and return it to e
    if(p > Length(L))
        return 0;
    LNode *dummy = new LNode;
    dummy->next = L;
    LNode *pre = dummy;

    for(int i=1; i<p; i++)
        pre = pre->next;
    
    LNode *delNode = pre->next;
    e = delNode->data;
    pre->next = delNode->next;
    delete delNode;
    L = dummy->next;
    delete dummy;
    return 1;
}

void Printlist(LinkList L)
{
    // Print linked list
    LNode *p = L;
    while(p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int Empty(LinkList L)
{
    return !L;
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