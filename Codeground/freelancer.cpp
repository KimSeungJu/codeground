#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int P[10000];
int Q[10000];
long int sum[10000];


int main() {

	setbuf(stdout, NULL);

	int T;
	int test_case;
	int N;
	int i, j;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {


		scanf("%d", &N);

		for (i = 0; i<N; i++) {
			sum[i] = 0;
		}
		for (i = 0; i<N; i++) {
			scanf("%d", &P[i]);
		}
		for (i = 0; i<N; i++) {
			scanf("%d", &Q[i]);
		}


		// i = 0
		if (P[0] > Q[0])
			sum[0] = P[0];
		else
			sum[0] = Q[0];


		// i = 1
		if (Q[1] < sum[0] + P[1]) {
			sum[1] = sum[0] + P[1];
		}
		else if (Q[1] > P[0] + P[1]) {
			sum[1] = Q[1];
		}



		for (i = 2; i<N; i++) {
			if (sum[i - 2] + Q[i] > sum[i - 1] + P[i]) {
				sum[i] = sum[i - 2] + Q[i];
			}
			else {
				sum[i] = sum[i - 1] + P[i];
			}

		}
		printf("Case #%d\n%ld\n", test_case, sum[N - 1]);

	}

	return 0;
}
