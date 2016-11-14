#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
vector<string> a;
int n, m, r = 0;
bool x = false;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        string z;
        cin >> z;
        a[i] = z;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#' && !x)
            {
                if (a[i - 1][j] == '*')
                {
                    x = true;
                    r++;
                }
            }
            else if (x && (a[i][j] == '.' || a[i][j] == '*'))
            {
                x = false;
            }
            if (j == m - 1)
                x = false;
        }
    }
    cout << r;
}
