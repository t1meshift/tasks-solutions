#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;
int n, max_difts = -1;
vector<pair<string, int>> words;

bool isVowel(char a)
{
	return
		a == 'a' ||
		a == 'e' ||
		a == 'i' ||
		a == 'o' ||
		a == 'u' ||
		a == 'y';
}

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	words.resize(n);
	for (int i = 0; i < n; i++)
	{
		string a;
		bool ff = false;
		cin >> a;
		words[i].first = a;

		int dipht_cnt = 0;

		if (a.size() < 2) ff = true;
		if (a.size() == 2 && isVowel(a[0]) && isVowel(a[1]))
		{
			dipht_cnt = 1;
			ff = true;
		}

		for (int j = 0; j < a.size(); j++)
		{
			if (ff) break;
			if (!isVowel(a[j]))
			{
				if (j + 2 < a.size())
				{
					if (isVowel(a[j + 1]) && isVowel(a[j + 2]) && j + 3 == a.size())
					{
						dipht_cnt++;
						break;
					}
					else if (isVowel(a[j + 1]) && isVowel(a[j + 2]) && !isVowel(a[j + 3]))
					{
						dipht_cnt++;
						j += 2;
					}
				}
			}
			else if (j == 0 && isVowel(a[j]) && isVowel(a[j+1]) && !isVowel(a[j+2]))
			{
				dipht_cnt++;
			}
		}
		words[i].second = dipht_cnt;
		if (max_difts < dipht_cnt)
			max_difts = dipht_cnt;
	}
	for (int i = 0; i < n; i++)
	{
		if (words[i].second == max_difts)
			cout << words[i].first << endl;
	}
}