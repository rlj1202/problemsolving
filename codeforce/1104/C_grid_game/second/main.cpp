#include <iostream>
#include <cstring>

using namespace std;

char str[1003];
int len;

char grid[6][6];

int main() {
	scanf("%s", str);
	len = strlen(str);

	for (int i = 1; i <= 4; i++) {
		grid[0][i] = 1;
		grid[5][i] = 1;
		grid[i][0] = 1;
		grid[i][5] = 1;
	}

	for (int i = 0; i < len; i++) {
		char cur = str[i] - '0';

		int result_r = 0;
		int result_c = 0;

		if (cur == 0) { // vertical
			bool succeed = false;
			for (int c = 1; c <= 4; c++) {
				for (int r = 1; r <= 4 - 1; r++) {
					if (grid[r][c] == 0 && grid[r + 1][c] == 0) {
						if ((grid[r][c - 1] == 1 && grid[r + 1][c - 1] == 1) ||
								(grid[r][c + 1] == 1 && grid[r + 1][c + 1] == 1)) {
							grid[r][c] = 1;
							grid[r + 1][c] = 1;

							result_r = r;
							result_c = c;

							succeed = true;
							break;
						}
					}
				}
				if (succeed) break;
			}
		} else { // horizontal
			bool succeed = false;
			for (int r = 1; r <= 4; r++) {
				for (int c = 1; c <= 4 - 1; c++) {
					if (grid[r][c] == 0 && grid[r][c + 1] == 0) {
						if ((grid[r - 1][c] == 1 && grid[r - 1][c + 1] == 1) ||
								(grid[r + 1][c] == 1 && grid[r + 1][c + 1] == 1)) {
							grid[r][c] = 1;
							grid[r][c + 1] = 1;

							result_r = r;
							result_c = c;

							succeed = true;
							break;
						}
					}
				}
				if (succeed) break;
			}
		}

		printf("%d %d\n", result_r, result_c);

		for (int r = 1; r <= 4; r++) {
			int sum = 0;
			for (int c = 1; c <= 4; c++)
				sum += grid[r][c];

			if (sum == 4) {
				for (int c = 1; c <= 4; c++)
					grid[r][c] = 0;
			}
		}

		for (int c = 1; c <= 4; c++) {
			int sum = 0;
			for (int r = 1; r <= 4; r++)
				sum += grid[r][c];

			if (sum == 4) {
				for (int r = 1; r <= 4; r++)
					grid[r][c] = 0;
			}
		}
	}

	return 0;
}
