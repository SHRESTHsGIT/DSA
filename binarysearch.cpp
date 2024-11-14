#include <iostream>
using namespace std;
int bse(int a[],int k,int n)
{
    int e=n-1,s=0,m=0;
    while(s<e)
    {
        m=(s/2)+(e/2);//the sum of e and s may ecceef the max value if the int 
        if(a[m]==k)
        {
            return m;
        }
        if(a[m]<k)
        {
            s=m+1;
        }
        else
        {
            e=m-1;
        }
    }
    return -1;
}
int main()
{
    int b[]={1,4,5,6,7,8,10,19};
    int i=bse(b,6,8);
    cout << "the index vlaue of the element is ="<<i<<endl;
    return 0;
}