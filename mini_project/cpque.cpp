// question 3B
#include <iostream>
using namespace std;
int main()
{
    int n,m, t, e, i = 0, c1 = 0, c2 = 0;
    m = 5;
    n=6;
    int a1[5]= {1,2,3,4,5}, a2[6]= {6,7,8,9,10,11}, a3[n + n];
    for (int k = 1; k >0; k++) // step
    {
        t = k % 4;            // remainder no of element to be entered in each step
        if (t == 2 || t == 3)//for step 
        {
            e = 2;
        }
        else
        {
            e = 1;
        }
        if (k % 2 == 1)//on odd step element from a1
        {
            for (int j = i; j < i + e ; j++)
            {
                a3[j] = a1[c1];
                c1++;
                c1=c1%m;
            }
            i = i + e ;
        }
        else//on even step element from a2
        {
            for (int j = i; j < i + e ; j++)
            {
                a3[j] = a2[c2];
                c2 ++;
                c2=c2%n;
            }
            i = i + e ;
            
        }
        if(i>=n+n)
            {
                break;
            }
    }
    cout<<endl<<"after the code-->"<<endl;
    for (int r = 0; r < n + n; r++)
    {
        cout << a3[r] << endl;
    }
    return 0;
}