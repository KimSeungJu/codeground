#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		int Answer = 0;
		int len;
		cin >> len;
		string abc;
		cin >> abc;

		int st[1000] = { 0 };
		int en[1000] = { 0 };
		int lenn[1000];
		int start = 0;
		int end = 0;
		int boo = 1;
		int ans_len = 0;

		int c = 0;
		for (int i = 0; i < len; i++)
		{
			if (abc.at(i) == 'a')
			{
				st[c] = i;
				c++;
			}
		}
		for (int k = 0; k < c; k++)
		{
			start = st[k];
			boo = 1;
			for (int i = start; i < len; i++)
			{
				if (abc.at(i) == 'e'&& boo == 1)
				{
					end = i;
					boo += 1;
					continue;
				}
				else if (abc.at(i) == 'i'&& boo == 2)
				{
					end = i;
					boo += 1;
					continue;
				}
				else if (abc.at(i) == 'o'&& boo == 3)
				{
					end = i;
					boo += 1;
					continue;
				}
				else if (abc.at(i) == 'u'&& boo == 4)
				{
					end = i;
					boo += 1;
					continue;
				}
			}
			if (boo == 5)
				en[k] = end;
			else
				en[k] = 0;
		}

		ans_len = 1000;
		for (int k = 0; k < c; k++)
		{
			//printf("%d %d\n", st[k], en[k]);
			lenn[k] = en[k] - st[k];
			if (lenn[k]>0 && lenn[k] < ans_len) //���̰��� �������
			{
				ans_len = en[k] - st[k];//���̰��� �信 ����
				Answer = st[k];
			}
			else if (lenn[k]>0 && lenn[k] == ans_len)//���� ���� ���� ���
			{
				if (Answer > st[k])//k�� ���� ��
					Answer = st[k];
			}
		}


		cout << "Case #" << test_case + 1 << endl;
		if (ans_len == 1000)
			cout << -1 << " " << -1 << endl;
		else
			cout << Answer + 1 << " " << Answer + 1 + ans_len << endl;
	}

	return 0;
}