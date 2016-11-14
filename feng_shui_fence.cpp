#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
 
using namespace std;
int n, m, k,x,i,ans1,ans2;
vector<int>  ch1, ch2;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    ch1.resize(n);
    ch2.resize(n);
     
     
    for (int i = 0; i < n; i++)
    {
        cin >> ch1[i];
        ch2[i] = ch1[i];
    }
    if (n == 1)
    {
        cout << ch1[0];
        return 0;
    }
    else
    {
        for (int i = 0; i < (n - 1); i = i + 1)
        {
 
            if ((ch1[i]<=ch1[i + 1]) && (i % 2 == 0))
            {
                ans1 += ch1[i + 1] - ch1[i]+1;
                ch1[i] = ch1[i + 1] + 1;
            }
            if ((ch1[i]>=ch1[i + 1])&&((i % 2) == 1))
            {
                ans1 += ch1[i ] - ch1[i+1]+1;
                ch1[i+1] = ch1[i] + 1;
            }
            if ((ch2[i]<=ch2[i + 1])&&((i % 2) == 1))
            {
                ans2 += ch2[i + 1] - ch2[i]+1;
                ch2[i] = ch2[i + 1] + 1;
            }
            if ((ch2[i]>=ch2[i + 1])&&((i % 2) == 0))
            {
                ans2 += ch2[i] - ch2[i + 1]+1;
                ch2[i + 1] = ch2[i] + 1;
            }
 
        }
        if (!(ans1 >= ans2))
        {
            for (int i = 0; i < n; i++)
                cout << ch1[i] << ' ';
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << ch2[i] << ' ';
            }
        }
        }
    }
