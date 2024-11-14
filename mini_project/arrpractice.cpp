#include <iostream>
#include <vector>
using namespace std;
void merge(int a[], int l1, int b[], int l2, int c[])
{
    int c1 = 0, c2 = 0, i = -1;
    while (c1 < l1 && c2 < l2)
    {
        i = i + 1;
        if (a[c1] < b[c2])
        {
            c[i] = a[c1];
            c1++;
        }
        else
        {
            c[i] = b[c2];
            c2++;
        }
        while (c1 < l1)
        {
            c[i] = a[c1];
            i++;
            c1++;
        }
        while (c2 < l2)
        {
            c[i++] = b[c2++];
        }
    }
}
void shift0(int e[], int l)
{
    for (int i = 0; i < l; i++)
    {
        if (e[i] == 0)
        {
            for (int j = i, t = 0; j < l - 1; j++)
            {
                e[j] = t;
                e[j] = e[j + 1];
                e[j + 1] = t;
            }
        }
    }
}
void ro(int a[], int n, int l)
{
    int t = 0;
    int temp[l];
    for (int i = 0; i < l; i++)
    {
        t = (i + n) % (l);
        temp[t] = a[i];
    }
    int k = 0;
    for (int i : temp)
    {
        a[k] = i;
        k++;
    }
}
int ifroso(int a[], int l)
{
    int i = 0, c = 0, t = 0;
    while (c <= 2)
    {
        if (a[i % l] > a[(i + 1) % l])
        {
            c = c + 1;
            if (c >= 2)
            {
                break;
            }
            t = i % l;
        }
        i++;
    }
    if (t == i % l)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool efroso(int a[],int l)//prob
{
    int c=0;
    for(int i=0;i<l;i++)
    {
        if (a[i]>a[i+1])
        {
            c=c+1;
        }
    }
    if(a[l-1]<a[0])
    {
        c=c+1;
    }
    return c<=1;
}
int main()
{
    // merge
    int a[] = {1, 3, 4, 6, 8, 9};
    int b[] = {2, 7, 10};
    int n = (sizeof(a) / sizeof(int)) + (sizeof(b) / sizeof(int));
    cout << "value of n >>" << n << endl;
    int l1 = sizeof(a) / sizeof(int), l2 = sizeof(b) / sizeof(int);
    cout << l1 << "  " << l2 << endl;
    int c[n];
    merge(a, l1, b, l2, c);
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }
    // shift zeroprogramme
    int d[8] = {0, 3, 5, 0, 5, 0, 12, 5};
    int l = sizeof(d) / sizeof(int);
    shift0(d, l);
    cout << "after the 0 shift " << endl;
    for (int i : d)
    {
        cout << i << endl;
    }
    // rotate array
    int t[] = {1, 3, 4, 6, 8, 9};
    cout << "thie is the rotated array -->" << endl;
    ro(t, 4, 6);
    for (int i : t)
    {
        cout << i << endl;
    }
    cout<<"array is roso -->"<<ifroso(t, 6)<<endl<<efroso(t,6);
    return 0;
}