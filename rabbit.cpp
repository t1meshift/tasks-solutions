#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int m, a, b, c;
    int ma, mb, mc;
    cin >> m >> a >> b >> c;
    ma = a*2;
    mb = b*3;
    mc = c*4;
    if ((ma >= mb) && (mb >= mc))
    {
        cout << m+ma+mb+mc;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
