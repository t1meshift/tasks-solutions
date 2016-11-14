#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

char a;
int add_cnt = 0, result = 0;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (cin >> a)
	{
		if (a == 'i')
		{
			add_cnt++;
			result++;
		}
		else
			result += add_cnt;
	}
	cout << result;	
}
