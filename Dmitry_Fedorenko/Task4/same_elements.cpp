#include <assert.h>
#include "same_elements.h"
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void testRemoveSameElements1();
void testRemoveSameElements2 ();
void testRemoveSameElements3 ();

Node *  primaryInitialization   (int data);
void    addToEnd                (Node **pEnd, int data);
void    showList                (Node * const pBegin);
void    removeSameElements      (Node **pBegin);

void Dmitry_Fedorenko::initTask4()
{
    cout << "Task4 was run" << endl;

    srand(time(nullptr));

    const int LENGTH_OF_LIST = 10;

    Node *pBegin = primaryInitialization(rand()%10);
    Node *pEnd = pBegin;

    for (int i=0;i<LENGTH_OF_LIST;i++) addToEnd(&pEnd,rand()%10);
    //showList(pBegin);
    removeSameElements(&pBegin);
    //showList(pBegin);
    cout << "Tests was run" << endl;
    testRemoveSameElements1();
    testRemoveSameElements2();
    testRemoveSameElements3();
    cout << "Tests passed!!!" << endl;
}

void removeSameElements (Node **pBegin)
{
    Node *pv = *pBegin;
    Node *pV = new Node;

    while (pv) {
        pV = pv->next;
        while (pV) {
            if (pv->data == pV->data) {
                Node *del = pV;
                pV = pV->next;
                (del->prev)->next = del->next;
                if (del->next) (del->next)->prev = del->prev;
                delete del;
            } else pV = pV->next;
        }
        pv = pv->next;
    }
}

void showList (Node * const pBegin)
{
    Node *pV = pBegin;
    while (pV) {
        cout << pV->data << ' ';
        pV = pV->next;
    }
    cout << endl;
}

Node * primaryInitialization(int data)
{
    Node *pV = new Node;
    pV->data = data;
    pV->next = nullptr;
    pV->prev = nullptr;
    return pV;
}

void addToEnd(Node **pEnd, int data)
{
    Node *pV = new Node;
    pV->data = data;
    pV->next = nullptr;
    pV->prev = *pEnd;
    (*pEnd)->next = pV;
    *pEnd = pV;
}

void testRemoveSameElements1 ()
{
    int a[] = {6,4,3,7,2,7,2,7,4,2,3,5,1,7};
    int b[] = {6,4,3,7,2,5,1};
    int j(0);

    Node *pBegin = primaryInitialization(a[0]);
    Node *pEnd = pBegin;

    for (int i=1;i<sizeof(a)/4;i++){
        addToEnd(&pEnd,a[i]);
    }
    removeSameElements(&pBegin);
    Node *pv = pBegin;
    while (pv) {
        assert((pv->data) == b[j]);
        j++;
        pv = pv->next;
    }
}

void testRemoveSameElements2 ()
{
    int a[] = {7,7,7,7,7,7,7,7,7,7,7,7};
    int b[] = {7};
    int j(0);

    Node *pBegin = primaryInitialization(a[0]);
    Node *pEnd = pBegin;

    for (int i=1;i<sizeof(a)/4;i++){
        addToEnd(&pEnd,a[i]);
    }
    removeSameElements(&pBegin);
    Node *pv = pBegin;
    while (pv) {
        assert((pv->data) == b[j]);
        j++;
        pv = pv->next;
    }
}

void testRemoveSameElements3 ()
{
    int a[] = {-5,-2,-56,4,6,0,1,-4,-2,-2,-5,-56,0};
    int b[] = {-5,-2,-56,4,6,0,1,-4};
    int j(0);

    Node *pBegin = primaryInitialization(a[0]);
    Node *pEnd = pBegin;

    for (int i=1;i<sizeof(a)/4;i++){
        addToEnd(&pEnd,a[i]);
    }
    removeSameElements(&pBegin);
    Node *pv = pBegin;
    while (pv) {
        assert((pv->data) == b[j]);
        j++;
        pv = pv->next;
    }
}
