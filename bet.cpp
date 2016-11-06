#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;
int n;

int main() 
{
	freopen("bet.in", "r", stdin);
	freopen("bet.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, c, r, g, b;
		int bet_r, bet_g, bet_b, bet_max;
		cin >> a >> c >> r >> g >> b;
		bet_r = a*((r + 1)*(r + 1) + g*g + b*b) + c*min(r + 1, min(g, b));
		bet_g = a*(r*r + (g + 1)*(g + 1) + b*b) + c*min(r, min(g + 1, b));
		bet_b = a*(r*r + g*g + (b + 1)*(b + 1)) + c*min(r, min(g, b + 1));
		bet_max = max(bet_r, max(bet_g, bet_b));
		if (bet_max == bet_r)
			cout << "RED" << endl;
		else if (bet_max == bet_g)
			cout << "GREEN" << endl;
		else if (bet_max == bet_b)
			cout << "BLUE" << endl;
	}
}