#include <iostream>

using namespace std;

int sort(int a[11])
{
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= i - 1;j++)
        {
            if (a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}

bool test(int i)
{
    bool boo = true;
    int b1[11] = {};
    int b2[11] = {};
    int c1[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int c2[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int d1[11] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int d2[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    switch (i)
    {
        case '1':
            sort(b1);
            for (int i=1; i<=10; i++)
            {
                if (!(b1[i] = b2[i]))
                {
                     boo = false;
                }

            }
            break;
        case '2':
            sort(c1);
            for (int i=1; i<=10; i++)
            {
                if (!(c1[i] = c2[i]))
                {
                    boo = false;
                }

            }
            break;
        case '3':
            sort(d1);
            for (int i=1; i<=10; i++)
            {
                if (!(d1[i] = d2[i]))
                {
                    boo = false;
                }
            }
            break;

            return boo;
    }




}

int main() {
    int a[11];
    for (int i=1; i<=10; i++)
    {
        cin>>a[i];
    }
    sort(a);
    for (int i=1; i<=10; i++)
    {
        cout<<a[i];
    }
    cout << endl;
    if (test(1) and test(2) and test(3))
    {
        cout << "true";
    } else
    {
        cout << "false";
    }

    return 0;
}

