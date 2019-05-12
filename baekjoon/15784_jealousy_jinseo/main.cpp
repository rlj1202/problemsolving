#include <iostream>

int N, a, b;
int grid[1003][1003];

int main() {
	scanf("%d %d %d", &N, &a, &b);
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			scanf("%d", &grid[r][c]);

	int jinseo = grid[a][b];
	bool sad = false;

	for (int i = 1; i <= N; i++) {
		if (a != i) {
			if (jinseo < grid[i][b]) {
				sad = true;
				break;
			}
		}
		if (b != i) {
			if (jinseo < grid[a][i]) {
				sad = true;
				break;
			}
		}
	}

	if (sad) printf("ANGRY\n");
	else printf("HAPPY\n");

	return 0;
}
