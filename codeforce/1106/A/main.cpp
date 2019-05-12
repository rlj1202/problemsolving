#include <iostream>

int N;
char grid[502][502];

int main() {
	scanf("%d", &N);
	for (int r = 1; r <= N; r++)
		scanf("%s", grid[r] + 1);

	int cnt = 0;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (grid[r][c] == 'X'
					&& grid[r - 1][c - 1] == 'X' && grid[r + 1][c + 1] == 'X'
					&& grid[r + 1][c - 1] == 'X' && grid[r - 1][c + 1] == 'X'
					) {
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
