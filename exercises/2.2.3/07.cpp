#include "sequence_list.cpp"

int MergeList(SeqList a, SeqList b, SeqList &c);

int main()
{
    SeqList a, b, c;
    InitList(a, 10);
    InitList(b, 10);
    InitList(c, 25);
    for(int i=0; i<10; i++)
        a.data[i] = i;
    a.length = 10;
    for(int i=0; i<10; i++)
        b.data[i] = i+10;
    b.length = 10;

    Printlist(a);
    Printlist(b);
    Printlist(c);
    MergeList(a, b, c);
    Printlist(c);
    return 0;
}

int MergeList(SeqList a, SeqList b, SeqList &c)
{
    if(a.length + b.length > c.MaxSize)
        return 0;
    int i = 0, j=0;
    while(i<a.length && j<b.length)
    {
        if(a.data[i] <= b.data[j])
        {
            c.data[c.length++] = a.data[i++];
        }else
        {
            c.data[c.length++] = b.data[j++];
        }
    }

    while(i < a.length)
    {
        c.data[c.length++] = a.data[i++];
    }

    while(j < b.length)
    {
        c.data[c.length++] = b.data[j++];
    }
    return 1;

}