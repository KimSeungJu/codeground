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

		//이동할 돌을 찾자
		//배열 크기만큼 반복
		for (int i = 0; i < num; i++)
		{
			//배열 - 현재 위치가 길이보다 작으면
			if (gogo[i] - pos <= len && gogo[i] - pos >0)
			{
				//저장 i가 증가할수록 최대 위치가 저장됨
				k = i;
				boo = true;
				if (k == num - 1)
				{
					pos = gogo[k];
					ans++;
				}
			}
			else //배열 = 현재 위치가 길이보다 커지면
			{
				if (boo == false)
					break;
				//포지션을 옮기고 브레이크
				pos = gogo[k];
				//답 증가
				ans++;
				//i 감소
				i--;
				boo = false;
			}

		}

		//현재 위치가 마지막 위치와 같아지면 정답
		if (pos == gogo[num - 1])
			Answer = ans;
		else
			Answer = -1;


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}