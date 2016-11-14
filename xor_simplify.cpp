#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <string>
 
using namespace std;
bool kal[27];
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string x;
    bool xyu = false;
    getline(cin, x);
    for (int i = 0; i < x.size(); i += 6)
        kal[(int)x[i] - 97] = !kal[(int)x[i] - 97];
 
    for (int i = 0; i < 27; i++)
    {
        if (kal[i])
        {
            if (xyu)
                cout << " xor " << (char)(i + 97);
            else
                cout << (char)(i + 97);
            xyu = true;
        }
    }
    if (!xyu)
        cout << '0';
}
