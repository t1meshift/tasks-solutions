#define _CRT_SECURE_NO_WARNINGS
 
#include <iostream>
#include <cmath>
#include <algorithm>
 
using namespace std;
int xx1, yy1, xx2, yy2, xx, yy;
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> xx1 >> yy1 >> xx2 >> yy2 >> xx >> yy;
    double cx = (xx1+.0 + xx2+.0) / 2., cy = (yy1+.0 + yy2+.0) / 2.0;
    double c_dist = min(sqrt((xx1 - xx)*(xx1 - xx) + (yy1 - yy)*(yy1 - yy)),
        min(sqrt((xx2 - xx)*(xx2 - xx) + (yy2 - yy)*(yy2 - yy)),
        min(sqrt((xx2 - xx)*(xx2 - xx) + (yy1 - yy)*(yy1 - yy)),
        sqrt((xx1 - xx)*(xx1 - xx) + (yy2 - yy)*(yy2 - yy)))));
 
    double dist = sqrt((cx - xx)*(cx - xx) + (cy - yy)*(cy - yy));
    if (c_dist < dist)
        cout << "CORNER";
    else
        cout << "CENTER";
}
