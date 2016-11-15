
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
int result = 0;
bool isWord = false;
int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	char a;
	while (cin >> noskipws >> a)
	{
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		{
			isWord = true;
		}
		else
		{
			if (isWord && a != '-')
			{
				isWord = false;
				result++;
			}
		}
	}
	cout << result + isWord;
}