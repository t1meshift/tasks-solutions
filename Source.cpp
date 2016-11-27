
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>


int n;
int field[1500][1500];
using namespace std;
int main()
{
	vector<pair<int, int>> cells_to_see = { {0, 0} };
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n; //размер стороны поля
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char a;
			cin >> a;
			field[i][j] = (a == '#' ? -1 : 0); //ставим стены
		}
	}

	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	if (n == 2)
	{
		if (field[0][1] == -1 && field[1][0] == -1)
			cout << -1;
		else
			cout << 2;
		return 0;
	}

	while (cells_to_see.size())
	{
		pair<int, int> current_cell = cells_to_see.front();
		int j = current_cell.first,
			k = current_cell.second;

		if (k > 0) //Шаг влево
			if (field[j][k - 1] != -1) // не стена
				if (j > 0 || k - 1 > 0) // не стартовая клетка
					if ((field[j][k - 1] > field[j][k] + 1) || (field[j][k - 1] == 0)) //клетка либо пустая, либо там не минимум
					{
						//инкремент и занесение куда надо
						field[j][k - 1] = field[j][k] + 1;
						cells_to_see.push_back({ j,k - 1 });
					}
		if (k < n - 1) //шаг вправо
			if (field[j][k + 1] != -1) // не стена
				if ((field[j][k + 1] > field[j][k] + 1) || (field[j][k + 1] == 0)) //клетка либо пустая, либо там не минимум
				{
					field[j][k + 1] = field[j][k] + 1;
					cells_to_see.push_back({ j,k + 1 });
				}

		if (j > 0) //шаг вверх
			if (field[j - 1][k] != -1) // не стена
				if (j - 1 > 0 || k  > 0) // не стартовая клетка
					if ((field[j - 1][k] > field[j][k] + 1) || (field[j - 1][k] == 0)) //клетка либо пустая, либо там не минимум
					{
						field[j - 1][k] = field[j][k] + 1;
						cells_to_see.push_back({ j - 1, k});
					}

		if (j < n - 1) //шаг вниз
			if (field[j + 1][k] != -1) // не стена
				if ((field[j + 1][k] > field[j][k] + 1) || (field[j + 1][k] == 0)) //клетка либо пустая, либо там не минимум
				{
					field[j + 1][k] = field[j][k] + 1;
					cells_to_see.push_back({ j + 1, k });
				}
		cells_to_see.erase(cells_to_see.begin());
	}
	cout << (field[n - 1][n - 1] > 0 ? field[n - 1][n - 1] : -1);
	return 0;
}