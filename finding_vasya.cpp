#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
vector<long long> a;
long long n, m, k,o,ans;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    cin >> o;
    a.resize(n);
    for (long long i = 0; i < o; i++)
    {
        long long e;
        cin >> e;
        if (n*m*e<k) 
        {
            continue;
        }
        long long k1 = k / (e*m)+1;
        if (k % (e*m) == 0){ k1--; }
        long long p = k - (k1 - 1)*(e*m);
        long long p1 = p / e+1;
        if (p % e == 0) { p1--; }
        if (p1>a[k1-1]) { a[k1-1] = p1; }
    }
 
    for (long long i1 = 0; i1 < n; i1++)
    {
        ans += a[i1];
    }
    if (ans > 0) { cout << ans; }
    else { cout << -1; }
}
