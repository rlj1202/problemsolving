#include <iostream>

int N, M;
int map[60][60];
int rows[60];
int cols[60];

int main() {
	scanf("%d %d", &N, &M);
	
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			char c;
			scanf(" %c", &c);
			if (c =='X') {
				map[n][m] = 1;
				rows[n]++;
				cols[m]++;
			}
		}
	}

	int cnt = 0;

	for (int n = 0; n < N; n++) {
		if (rows[n] != 0) continue;

		int m = 0;
		while (cols[m] != 0 && m < M) m++;
		if (m == M) m--;

		map[n][m] = 1;
		rows[n]++;
		cols[m]++;

		cnt++;
	}

	for (int m = 0; m < M; m++) {
		if (cols[m] != 0) continue;

		int n = 0;
		while (rows[n] != 0 && n < N) n++;
		if (n == N) n--;

		map[n][m] = 1;
		rows[n]++;
		cols[m]++;

		cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
