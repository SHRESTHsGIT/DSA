#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    // constructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    // destructor
    ~node()
    {
        int v = this->data;
        // memory free
        if (this->next != NULL)
        {
            this->next = NULL; /// doubt//////
        }
        cout << "memory is free for node of value" << this->data << endl;
    }
};

// func
int printll(node *&head)
{
    node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        c++;
    }
    cout<<endl;
    return c;
}
int sizeofll(node *&head)
{
    node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}
void inhead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void intail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void inpo(int po, node *&head, int d, node *&tail)
{
    if (po == 1)
    {
        inhead(head, d);
    }
    else
    {
        int c = 1;
        node *cur=head;
        while (c<po)
        {
            cur = cur->next;
            c++;
        }
        if (cur->next == NULL)
        {
            intail(tail, d);
        }
        else
        {
            node *temp = new node(d);
            temp->next = cur->next;
            cur->next = temp;
        }
    }
}
void delnod(int po, node *&head, node *&tail)
{
    // del 1st node
    if (po == 1)
    {
        node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleteing middle or last node
        node *cur = head;
        node *pre = NULL;
        int cnt = 1;
        while (cnt < po)
        {
            pre = cur;
            cur = cur->next;
            cnt++;
        }
        pre->next = cur->next;
        cur->next = NULL;
        if (pre->next == NULL)
        {
            tail = pre;
        }
        delete cur;
    }
}
int main()
{
    int ch;
    node *head;
    node *tail;
    node *n1 = new node(18);
    head = n1;
    tail = n1;
    cout << "1-print\n2-len\n3-inhead\n4-intail\n5-inpos\n6-delnode" << endl;
    ch=1;
    while (ch < 7&& ch>0)
    {
        cout<<"entre the choise=";
        cin >> ch;
        cout<<endl;
        switch (ch)
        {
        case 1:
        cout<<"list-\n"<<endl;
            printll(head);
            break;
        case 2:
            cout<<"\nlen="<<sizeofll(head)<<endl;
            break;
        case 3:
        {
            int d;
            cout << "enter the value for the node" << endl;
            cin >> d;
            inhead(head, d);
        }
        break;
        case 4:
        {
            int d;
            cout << "entre the value for tail" << endl;
            cin >> d;
            intail(tail, d);
        }
        break;
        case 5:
        {
            int d, po;
            cout << "enter the value" << endl;
            cin >> d;
            cout << "enter the position" << endl;
            cin >> po;
            inpo(po, head, d, tail);
        }
        break;
        case 6:
        {
            int po;
            cout << "enter the postiition" << endl;
            cin >> po;
            delnod(po, head, tail);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}