#include <iostream>
#define ElemType int

// Strcuture declaration
typedef struct LNode
{
    ElemType data;                                   // Data
    struct LNode *next;                              // Pointer to the next node
    LNode(ElemType x):data(x), next(NULL) {}         // Constructor
}LNode, *LinkList;

// Basic operations
void InitList(LinkList &L);                          // Initialize list
int Length(LinkList L);                              // Return the length of given linked list
LNode *LocateElem(LinkList L, ElemType e);           // Return the first node with given value
LNode *GetElem(LinkList L, int p);                   // Return node in given position
LinkList List_HeadInsert(LinkList &L);               // Create Linked list using head insert
LinkList List_TailInsert(LinkList &L);               // Create Linked list using tail insert
int ListInsert(LinkList &L, int p, ElemType e);      // Insert element e to given position
int ListDelete(LinkList &L, int p, ElemType &e);     // Delete element in given opsition, return its value to e
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
    L = NULL;
}

int Length(LinkList L)
{
    // Return the length of given linked list

    int length = 0;
    LNode *p = L;
    // Scan list, length increase 1 until meets the last node
    while(p)
    {
        length++;
        p = p->next;
    }
    return length;
}

LNode *LocateElem(LinkList L, ElemType e)
{
    // Return the first node with given value

    LNode *p = L;
    // Scan list until value matches
    while(p && p->data != e)
        p = p->next;

    return p;
}

LNode *GetElem(LinkList L, int p)
{
    // Return node in given position

    LNode *n = L;
    // If the position is illegal, fails
    if(p<1 || p>Length(L))
        return NULL;
    // Scan list until reach the given position
    for(int i=1; i<p; i++)
    {
        n = n->next;
    }
    return n;
}

LinkList List_HeadInsert(LinkList &L)
{
    // Create Linked list using head insert

    // Set dummy node to create a virtual head node
    LNode *dummy = new LNode(0);
    dummy->next = L;
    // Pointer to new node
    LNode *p;
    // Value of the new node
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        // Allocate space for the new node
        p = new LNode(x);
        // Insert
        p->next = dummy->next;
        dummy->next = p;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    // Delete dummy node
    L = dummy->next;
    delete dummy;
    return L;
}

LinkList List_TailInsert(LinkList &L)
{
    // Create Linked list using head insert

    // Set dummy node to create a virtual head node
    LNode *dummy = new LNode(0), *r = dummy;
    dummy->next = L;
    // Pointer to new node
    LNode *p;
    // Value of the new node
    ElemType x;
    std::cout << "Enter data:";
    std::cin >> x;
    while(x != 9999)
    {
        // Allocate space for the new node
        p = new LNode(x);
        // Insert
        r->next = p;
        r = r->next;
        std::cout << "Enter data:";
        std::cin >> x;
    }
    // Delete dummy node
    L = dummy->next;
    delete dummy;
    return L;
}

int ListInsert(LinkList &L, int p, ElemType e)
{
    // Insert element e to given position

    // If the positon is illegal, insertion fails
    if( p<1|| p>Length(L)+1 )
        return 0;
    // Set dummy node to create a virtual head node
    LNode *dummy = new LNode(0);
    dummy->next = L;
    LNode *pre = dummy;
    LNode *newNode = new LNode(e);

    // Scan to the previous position of the position to be inserted
    for(int i=1; i<p; i++)
        pre = pre->next;
    // Insert
    newNode->next = pre->next;
    pre->next = newNode;
    // Delete dummy node
    L = dummy->next;
    delete dummy;
    return 1;
}

int ListDelete(LinkList &L, int p, ElemType &e)
{
    // Delete element in given opsition, return its value to e
    
    // If the position id illegal, deletion fails
    if( p<1 || p>Length(L) )
        return 0;
    // Set dummy node to create a virtual head node
    LNode *dummy = new LNode(0);
    dummy->next = L;
    LNode *pre = dummy;
    // Scan to the previous position of the position to be deleted
    for(int i=1; i<p; i++)
        pre = pre->next;
    // Delete
    LNode *delNode = pre->next;
    e = delNode->data;
    pre->next = delNode->next;
    delete delNode;
    // Delete dummy node
    L = dummy->next;
    delete dummy;
    return 1;
}

void Printlist(LinkList L)
{
    // Print linked list
    LNode *p = L;
    // Scan list and print each element
    while(p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int Empty(LinkList L)
{
    // If the list is empty, return 1
    // Else return 0

    return !L;
}

void DestroyList(LinkList &L)
{
    // Destroy given list and release space

    LNode *p;
    // Scan list and release space for each node 
    while(L)
    {
        p = L->next;
        delete L;
        L = p;
    }
}