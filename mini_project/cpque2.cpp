#include <iostream>
#include <string>
#include <array>
using namespace std;

int main()
{
    int tc, lr, l = 0;
    cin >> tc;
    long int a[tc];
    for (int i = 0; i < tc; i++)
    {
        cin >> a[i];
    }
    // array for revenue
    int c = 0;
    for (int i = 0, k = 0; k < tc; k++)
    {
        if (a[i] <= a[k])
        {
            c++;
        }
        lr = c * 1ll * a[i];
        if (lr >= l)
        {
            l = lr;
        }
        c = 0;
        i++;
    }
    cout << l;
}