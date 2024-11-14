/*precise sq root*/
#include <iostream>
using namespace std;
int bsq(int a)
{
    int ans=0;
    int s=0,e=a,mid=0;
    
    while(s<=e)
    {
        mid=s+(e-s)/2;
        if((mid*mid)==a)
        {
            ans=mid;
            return ans;
        }
        if((mid*mid)>a)
        {
            e=mid-1;
        }
        if((mid*mid)<a)
        {
            ans=mid;//store karna ip
            s=mid+1;
        }

    }
    return ans;
}
double pre(int a,double b,int d)
{
    double i=0.1;
    double k=b;
    k=k+i;
    for(int r=1;r<=d;r++)
    {
        for(double j=k;(j*j)<a;)
        {
            k=j;
            j=j+i;
            //cout<<endl<<j;
        }
        i=i/10;
    }
    return k;
}
int main()
{
    int n,d,t;
    double sr;
    cout<<"entr the num =";
    cin>>n;
    cout<<endl <<"enter the digit for precision=";
    cin>>d;
    t=bsq(n);
    sr=pre(n,t,d);
    cout<<endl<<"ans="<<sr;
    return 0;
}