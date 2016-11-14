
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;
int k[1000000];
int p;
int n;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;

	for (int i = 0; i < 1000000; i++)
		k[i] = 0;
    
	for (int i = 0; i < n; i++)
	{
		int id, correct, detailed;
		cin >> id >> correct >> detailed;
		if (correct)
			p += (detailed + 1) * 20 + 10 * (k[id]++);
		else
			p += 10;
	}
  
	cout << p;
}
