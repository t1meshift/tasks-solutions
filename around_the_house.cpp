#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int64_t width, height, wtime;
    cin >> width >> height >> wtime;
    wtime = wtime%((width+height)*2); //still South
    if (wtime - width >= 0)
    {
        wtime -= width;
        if (wtime - height >= 0)
        {
            wtime -= height;
            if (wtime - width >= 0)
            {
                wtime -= width;
                if (wtime - height >= 0)
                {
 
                }
                else
                {
                    cout << "W";
                }
            }
            else
            {
                cout << "N";
            }
        }
        else
        {
            cout << "E";
        }
    }
    else
    {
        cout << "S";
    }
    return 0;
}
