#include <iostream>

using namespace std;

struct  Node
{
    int x;
    Node *Next;
};

class List
{
    Node *Head,*Tail;
    int size;
public:
    List():Head(NULL),Tail(NULL),size(0){};
    void Add(int x);
    void Show(int size);
};

void List::Add(int x)
{
    size++;
    Node  *temp=new Node;
    temp->Next=Head;
    temp->x=x;

    if (Head!=NULL)
    {
        Tail->Next=temp;
        Tail=temp;
    }
    else Head=Tail=temp;
}


void List::Show(int size)
{
    Node *tempHead=Head;

    int temp=size;
    while (temp!=0)
    {  if (!(temp == size)) {
            cout << "->";
        }
        cout << tempHead-> x;
        tempHead=tempHead->Next;
        temp--;
    }
    cout << endl;
}

int main()
{   List spisok;
    int n;
    cout << "введите кол-во элементов кольцевого списка: ";
    cin >> n;
    for (int i =1; i<=n; i++) {
        int a;
        cin >> a;
        spisok.Add(a);
    }
    cout << "Элементы созданного кольцевого списка";
    for(int i =1; i<=2*n; i++) {
        spisok.Show(i);
    }

    return 0;
}