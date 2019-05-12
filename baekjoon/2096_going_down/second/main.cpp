#include <iostream>
#include <algorithm>

using namespace std;

int N;
char grid[100005][3];

int main() {
	scanf("%d", &N);
	for (int r = 0; r < N; r++)
		for (int c = 0; c < 3; c++)
			scanf("%d", &grid[r][c]);

	int tmp1[3], tmp2[3], tmp3[3], tmp4[3];

	int *min_prev = tmp1;
	int *min_cur = tmp2;

	int *max_prev = tmp3;
	int *max_cur = tmp4;

	for (int c = 0; c < 3; c++) max_prev[c] = min_prev[c] = 0;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < 3; c++) max_cur[c] = grid[r][c];
		for (int c = 0; c < 3; c++) min_cur[c] = grid[r][c];

		for (int c = 0; c < 3; c++) {
			int max_next = 0;
			for (int d = -1; d <= 1; d++) {
				if (c + d < 0 || 3 <= c + d) continue;
				max_next = max(max_next, max_prev[c + d]);
			}
			max_cur[c] += max_next;

			int min_next = 0x3f3f3f3f;
			for (int d = -1; d <= 1; d++) {
				if (c + d < 0 || 3 <= c + d) continue;
				min_next = min(min_next, min_prev[c + d]);
			}
			min_cur[c] += min_next;
		}
		
		int *max_tmp = max_prev;
		max_prev = max_cur;
		max_cur = max_tmp;

		int *min_tmp = min_prev;
		min_prev = min_cur;
		min_cur = min_tmp;
	}

	int result_max = 0;
	for (int c = 0; c < 3; c++) result_max = max(result_max, max_prev[c]);

	int result_min = 0x3f3f3f3f;
	for (int c = 0; c < 3; c++) result_min = min(result_min, min_prev[c]);

	printf("%d %d\n", result_max, result_min);

	return 0;
}
