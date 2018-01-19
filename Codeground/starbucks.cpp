#include <iostream>

using namespace std;

char Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 'N';
		int man[30] = { 0 };
		int menu[20] = { 0 };
		int man_num = 0;
		int menu_num = 0;
		int budget = 0;
		int sum = 0;

		cin >> man_num >> menu_num >> budget;

		for (int i = 0; i < man_num; i++)
			cin >> man[i];

		for (int i = 0; i < menu_num; i++)
			cin >> menu[i];

		for (int i = 0; i < menu_num; i++)
		{
			for (int j = 0; j < man_num; j++)
			{
				if (man[j] == i + 1)
					sum += menu[i];
			}
		}

		if (sum <= budget)
			Answer = 'Y';
		else
			Answer = 'N';

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
