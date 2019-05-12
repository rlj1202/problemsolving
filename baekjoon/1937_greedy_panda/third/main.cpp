#include <iostream>
#include <algorithm>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N;
int grid[502][502];

int len[502][502];

int getlen(int r, int c) {
	if (len[r][c] != 0) return len[r][c];

	int result = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (grid[r][c] < grid[nr][nc]) result = max(result, getlen(nr, nc));
	}

	return len[r][c] = result + 1;
}

int main() {
	scanf("%d", &N);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int amount;
			scanf("%d", &amount);
			grid[r][c] = amount;
		}
	}

	int result = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) result = max(result, getlen(r, c));
	}
	printf("%d\n", result);

	return 0;
}
