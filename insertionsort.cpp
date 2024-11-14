#include <iostream>
using namespace std;
class node
{
public:
    node *pre;
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->pre = NULL;
    }
    ~node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        if (this->pre != NULL)
        {
            this->pre = NULL;
        }
        cout << "memory is now free for node with data " << this->data << endl;
    }
};

// FUNC
void printdll(node *&head)
{
    node *tem = head;
    while (tem != NULL)
    {
        cout << tem->data << " ";
        tem = tem->next;
    }
}

int sizedll(node *&head)
{
    int c = 1;
    node *tem = head;
    while (tem != NULL)
    {
        tem = tem->next;
        c++;
    }
    return --c;
}

void inhead(node *&head, int d)
{
    node *tem = new node(d);
    tem->next = head;
    head->pre = tem;
    head = tem;
}
void inpo(node *&head, int po, int d)
{
    node *tem = new node(d); // new node
    node *t = head;          // marker
    int c = 1;
    if (po == 1)
    {
        inhead(head, d);
    }
    else
    {
        while (c < po && t != NULL)
        {
            t = t->next;
            c++;
        }
        if (t->next == NULL)
        {
            tem->next = t->next;
            t->next = tem;
            tem->pre = t;
        }
        else
        {
            tem->next = t->next;
            t->next->pre = tem;
            t->next = tem;
            tem->pre = t;
        }
    }
}

void delnod(node *&head, int po)
{
    int c = 1;
    node *tem = head;
    if (po == 1)
    {
        tem->next->pre = NULL;
        tem->next = NULL;
        delete tem;
    }
    else
    {
        while (c < po && tem != NULL)
        {
            tem = tem->next;
            c++;
        }
        node *pre = tem->pre;
        node *nex = tem->next;
        tem->next = NULL;
        tem->pre = NULL;
        delete tem;
        if (nex == NULL)
        {
            pre->next = nex;
        }
        else
        {
            pre->next = nex;
            nex->pre = pre;
        }
    }
}
void sortll(node *&head)
{
    int n = sizedll(head);
    node *a[n];
    node *te = head;
    node *k;
    for (int i = 0; i < n; i++)
    {
        a[i] = te;
        te = te->next;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i]->data) > (a[j]->data))
            {
                k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            a[i]->next = NULL;
        }
        else
        {
            a[i]->next = a[i+1];
        }
        //pre
        if (i == 0)
        {
            a[i]->pre = NULL;
        }
        else
        {
            a[i]->pre = a[i-1];
        }
    }
    head=a[0];

}
int main()
{
    node *head = new node(10);
    node *tail = head;
    inhead(head, 23);
    inhead(head, 45);
    inpo(head, 2, 56);
    inhead(head, 78);
    inhead(head, 67);
    inhead(head, 89);
    printdll(head);
    cout<<endl<<"after sorting "<<endl;
    sortll(head);
    printdll(head);
    return 0;
}