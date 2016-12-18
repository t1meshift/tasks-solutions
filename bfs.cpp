#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
int n, m, s, col = 0;



int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m >> s;
	s--;
	if (!n)
	{
		cout << 0;
		return 0;
	}

	vector<vector<int>> g(n);
	vector<int> v(n);
	vector<int> q(n);
	v[s] = 1;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b-1);
		g[b - 1].push_back(a - 1);
	}
	int l = 0, r = 0;
	q[r++] = s;
	while (l < r)
	{
		int c = q[l++];
		for (int j = 0; j < g[c].size(); j++)
		{
			if (!(v[g[c][j]]++))
			{
				q[r++] = g[c][j];
			}
		}
	}
	if (r < n)
	{
		cout << -1;
		return 0;
	}
	else
	{
		for (int i = 0; i < r; i++) 
			cout << q[i] + 1 << " ";
	}
	
}