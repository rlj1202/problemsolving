#include <cstdio>

double table[7][7][7][1003];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			for (int k = 1; k <= 6; k++) {
				table[i][j][k][3] = 1.0/(6*6*6);
			}
		}
	}
	for (int n = 4; n <= N; n++) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				for (int k = 1; k <= 6; k++) {
					table[i][j][k][n] = table[i][j][k][n - 1];

					for (int u = 1; u <= 6; u++) {
						table[i][j][k][n] += table[u][i][j][n - 1];
					}
				}
			}
		}
	}

	return 0;
}
