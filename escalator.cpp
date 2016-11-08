#define _CRT_SECURE_NO_WARNINGS
#define nums_cnt(x) (9*powl(10,x))

#include <iostream>
#include <cmath>

using namespace std;
unsigned long long n = 1, res = 0;


int main() 
{
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	cin >> n;
	if (n < 11)
	{
		cout << (n == 1) ? 1 : 2;
		return 0;
	}

	if (n % 10) res += floor(log10(n) + 1);
	long long sum_of_nums = n/10;
	int pow_of_10 = 0;
	while (sum_of_nums > 0) 
	{
		if (sum_of_nums >= nums_cnt(pow_of_10))
		{
			res += nums_cnt(pow_of_10)*(pow_of_10+2);
			sum_of_nums -= nums_cnt(pow_of_10);
			pow_of_10++;
		}
		else
		{
			res += sum_of_nums*(pow_of_10 + 2);
			sum_of_nums = 0;
		}
	}
	cout << res+1;
}