#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <string>
#include <cmath>
 
using namespace std;
int n, m, k, x, i, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    x = n - k;
    if (!(m == 0))
    {
        for (i = 0; m*pow(2, i) <= x; i++)
        {
 
        }
        ans = ((n - m*pow(2, i)) / (x + .0)) + i;
        if (!(((int)(n - m*pow(2, i))) % x) == 0) { ans++;
         
        }
        cout << ans;
    }
    else
    {
        cout << -1;
    }
     
}
