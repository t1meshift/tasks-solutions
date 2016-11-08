#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
int n, k = 0;
string curr_marks;


int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	getline(cin, curr_marks); //endl
	while (n--)
	{
		getline(cin, curr_marks);
		istringstream iss(curr_marks);
		int curr_mark, cnt, sum = 0;
		iss >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			iss >> curr_mark;
			sum += curr_mark;
		}
		if (round((double)sum / (double)cnt) < round((double)(sum + 5) / (double)(cnt + 1)))
			k++;
	}
	cout << k;
}