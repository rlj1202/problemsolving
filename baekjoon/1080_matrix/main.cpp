#include <iostream>

int N, M;
int A[50][50];
int B[50][50];
int cnt;

void read(int (*matrix)[50]) {
	for (int n = 0; n < N; n++) {
		char raw[51];
		scanf("%s", raw);
		for (int m = 0; m < M; m++) {
			matrix[n][m] = raw[m] - '0';
		}
	}
}

void inverse(int (*matrix)[50], int n, int m) {
	for (int i = n; i < n+3; i++) {
		for (int j = m; j < m+3; j++) {
			matrix[i][j] = !matrix[i][j];
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	read(A);
	read(B);

	for (int n = 0; n <= N - 3; n++) {
		for (int m = 0; m <= M - 3; m++) {
			if (A[n][m] != B[n][m]) {
				inverse(A, n, m);
				cnt++;
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (A[n][m] != B[n][m]) {
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
