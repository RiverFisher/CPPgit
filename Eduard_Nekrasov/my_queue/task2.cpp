//
// Created by edward on 21.01.18.
//

#include "task2.h"
#include <iostream>

using namespace std;

struct queue
{
    queue* next;
    int key;
};

void add(int k, queue **q)
{
    queue* check = NULL;
    check = new queue;
    check->key = k;
    check->next = *q;
    *q = check;
}

void remove(queue **q)
{
    queue* check = *q;
    if (check->next != NULL)
    {
        while (check->next->next) {
            check = check->next;
        }
        check->next = NULL;
    }
    else
    {
        *q = NULL;
    }
}

void print(queue *q)
{
    queue* check = q;
    while(check)
    {
        cout << check->key;
        if (check->next)
        {
            cout << "->";
        }
        check = check->next;
    }
    cout << endl;
}

void find(queue *q)
{
    queue* check = q;
    while (check->next)
    {
        check = check->next;
    }
    cout << check->key <<endl;
}

void Eduard_Nekrasov::initTask2() {

    setlocale(0, "rus");
    queue* end = NULL;

    int n;
    bool k = true;
    setlocale(0, "rus");
    while (k)
    {
        cout << "1: Добавить элемент в очередь" << endl;
        cout << "2: Убрать элемент из очереди" << endl;
        cout << "3: Показать 1 элемент в очереди" << endl;
        cout << "4: Показать последний элемент в очереди" << endl;
        cout << "5: Показать все элементы очереди" << endl;
        cout << "0: Выйти" << endl;

        cin >> n;
        switch (n)
        {
            case 1:
                int s;
                cout << "Введите число: ";
                cin >> s;
                add(s, &end);
                cout << "complete!" << endl;
                break;

            case 2:
                if (end != NULL)
                {
                    remove(&end);
                    cout << "complete!" << endl;
                }
                else
                {
                    cout << "Список пуст!" << endl;
                }
                break;

            case 3:
                if (end != NULL)
                {
                    find(end);
                }
                else
                {
                    cout << "Список пуст!" << endl;
                }
                break;

            case 4:
                if (end != NULL)
                {
                    cout << end->key << endl;
                }
                else
                {
                    cout << "Список пуст!" << endl;
                }
                break;

            case 5:
                if (end != NULL)
                {
                    print(end);
                }
                else
                {
                    cout << "Список пуст!" << endl;
                }
                break;

            case 0:
                k = false;
                break;

            default:
                break;
        }
    }
}