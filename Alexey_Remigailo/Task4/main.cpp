#include <iostream>

struct pList
{
    char data;
    pList *next;
};

class List
{
    pList *first;
public:
    List(): first() {}
    void add(char x)
    {
        if(!first)
        {
            first = new pList;
            first->data = x;
            first->next = 0;
        }
        else
        {
            pList *curr = new pList;
            curr->data = x;
            curr->next = first;
            first = curr;
        }
    }
    void show()
    {
        pList *curr = first;
        while (curr)
        {
            std::cout << curr->data << ' ';
            curr = curr->next;
        }
        std::cout << '\n';
    }
    void deleteDublicate()
    {
        pList *bufI = 0;
        bool firstWasChanged = false;
        for (pList *i = first; i; i = i->next)
        {
            if (firstWasChanged)
            {
                i = first;
                firstWasChanged = false;
            }
            bool isDublicate = false;
            pList *bufJ = first;
            for (pList *j = first; j; j = j->next)
            {
                if (i->data == j->data && i != j)
                {
                    bufJ->next = j->next;
                    delete j;
                    j = bufJ;
                    isDublicate = true;
                }
                bufJ = j;
            }
            if (isDublicate)
            {
                if (i == first)
                {
                    bufI = i->next;
                    delete i;
                    i = bufI;
                    first = i;
                    if (!i) return;
                    firstWasChanged = true;
                }
                else
                {
                    bufI->next = i->next;
                    delete i;
                    i = bufI;
                }
            }
            bufI = i;
        }
    }
    ~List()
    {
        pList *curr = first;
        while (first)
        {
            curr = first->next;
            delete first;
            first = curr;
        }
        first = 0;
    }
};

int main()

{
    List list;
    list.add('a');
    list.add('a');
    list.add('a');
    list.add('a');
    list.add('f');
    list.add('r');
    list.add('B');
    list.add('A');
    list.add('a');
    list.add('a');
    list.add('c');
    list.deleteDublicate();
    list.show();
}
