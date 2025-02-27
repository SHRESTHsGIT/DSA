#include "bits/stdc++.cpp"
using namespace std;
const int k=1e5;
vector<int> arr(k,-1);

int fib(int n)
{
    //base case
    if(n==1)
    {
        arr[1]=1;
        return arr[1];
    }
    if(n==0)
    {
        arr[0]=0;
    }
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    return fib(n-1)+fib(n-2);
}
int main()
{
    
    
    return 0;
}