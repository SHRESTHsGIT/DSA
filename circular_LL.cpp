#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = this;
    }
    ~node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        cout << "the memory of the node with data =" << this->data << "is freed" << endl;
    }
};
int main()
{

    return 0;
}