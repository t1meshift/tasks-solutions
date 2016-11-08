#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>

using namespace std;
multiset<int> nums;
int n, nn;

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	while (n--)
	{
		cin >> nn;
		nums.insert(nn);
	}
	for (auto it = nums.begin(); it != nums.end(); ++it)
		cout << *it << " ";
}