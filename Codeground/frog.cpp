#include <iostream>

using namespace std;

int Answer;
int gogo[1000000] = { 0 };
int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		int num;
		int len;
		int ans = 0;
		int pos = 0;
		gogo[1000000] = { 0 };

		cin >> num;
		for (int i = 0; i < num; i++)
			cin >> gogo[i];

		cin >> len;

		int k = 0;
		bool boo = false;

		//�̵��� ���� ã��
		//�迭 ũ�⸸ŭ �ݺ�
		for (int i = 0; i < num; i++)
		{
			//�迭 - ���� ��ġ�� ���̺��� ������
			if (gogo[i] - pos <= len && gogo[i] - pos >0)
			{
				//���� i�� �����Ҽ��� �ִ� ��ġ�� �����
				k = i;
				boo = true;
				if (k == num - 1)
				{
					pos = gogo[k];
					ans++;
				}
			}
			else //�迭 = ���� ��ġ�� ���̺��� Ŀ����
			{
				if (boo == false)
					break;
				//�������� �ű�� �극��ũ
				pos = gogo[k];
				//�� ����
				ans++;
				//i ����
				i--;
				boo = false;
			}

		}

		//���� ��ġ�� ������ ��ġ�� �������� ����
		if (pos == gogo[num - 1])
			Answer = ans;
		else
			Answer = -1;


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}