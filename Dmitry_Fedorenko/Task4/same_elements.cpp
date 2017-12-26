#include "same_elements.h"
#include "iostream"

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

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

