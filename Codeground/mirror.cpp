
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int Answer;
int a[1000][1000] = { 0 };
int map[1000][1000] = { 0 };

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%1d", &a[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] = 0;

		int x = 0, y = 0;
		int g = 1;

		while (true)
		{
			if (x < 0 || y < 0 || x >= n || y >= n)
				break;

			if (a[y][x] == 0)
			{
				if (g == 1)
					x++;
				else if (g == 2)
					y++;
				else if (g == 3)
					x--;
				else if (g == 4)
					y--;
			}
			else if (a[y][x] == 1)
			{
				map[y][x] = 1;
				if (g == 1)
				{
					g = 4;
					y--;
				}
				else if (g == 2)
				{
					g = 3;
					x--;
				}
				else if (g == 3)
				{
					g = 2;
					y++;
				}
				else if (g == 4)
				{
					g = 1;
					x++;
				}
			}
			else if (a[y][x] == 2)
			{
				map[y][x] = 1;
				if (g == 1)
				{
					g = 2;
					y++;
				}
				else if (g == 2)
				{
					g = 1;
					x++;
				}
				else if (g == 3)
				{
					g = 4;
					y--;
				}
				else if (g == 4)
				{
					g = 3;
					x--;
				}
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (map[i][j] == 1)ans++;

		Answer = ans;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
