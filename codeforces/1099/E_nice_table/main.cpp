#include <iostream>

int N, M;
char grid[300005];

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			int index = m + (n - 1) * M;
			scanf("%c", grid + index);
		}
	}


	return 0;
}
