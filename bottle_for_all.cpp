#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

multiset<int> a;
int n, m;

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int ai;
		cin >> ai;
		a.insert(ai);
	}
	while (m--) {
		int ai = *a.rbegin() / 10;
		a.erase(prev(a.end()));
		a.insert(ai);
	}
	cout << accumulate(a.begin(), a.end(), 0);
}