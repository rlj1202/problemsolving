#include <iostream>
#include <algorithm>

using namespace std;

int sudoku[9][9];

int rowmasks[9];
int colmasks[9];
int blockmasks[9];

int blanklen;
pair<int, int> blanks[81];

int main() {
	for (int r = 0; r < 9; r++) {
		rowmasks[r] = (1 << 9) - 1;

		for (int c = 0; c < 9; c++) {
			scanf("%d", &sudoku[r][c]);
			if (sudoku[r][c] == 0) blanks[blanklen++] = {r, c};

			if (sudoku[r][c] != 0)
				rowmasks[r] ^= 1 << (sudoku[r][c] - 1);
		}
	}

	for (int c = 0; c < 9; c++) {
		colmasks[c] = (1 << 9) - 1;

		for (int r = 0; r < 9; r++) {
			if (sudoku[r][c] != 0)
				colmasks[c] ^= 1 << (sudoku[r][c] - 1);
		}
	}

	for (int bi = 0; bi < 3; bi++) {
		for (int bj = 0; bj < 3; bj++) {
			int blockindex = bj + bi * 3;
			blockmasks[blockindex] = (1 << 9) - 1;

			for (int r = 0; r < 3; r++) {
				for (int c = 0; c < 3; c++) {
					if (sudoku[bi * 3 + r][bj * 3 + c] != 0)
						blockmasks[blockindex] ^= 1 << (sudoku[bi * 3 + r][bj * 3 + c] - 1);
				}
			}
		}
	}

	bool updated = true;
	while (updated) {
		updated = false;
		for (int i = 0; i < blanklen; i++) {
			pair<int, int> cur = blanks[i];
			if (sudoku[cur.first][cur.second] != 0) continue;

			int bi = cur.first / 3;
			int bj = cur.second / 3;
			int blockindex = bj + bi * 3;

			int mask = rowmasks[cur.first] & colmasks[cur.second] & blockmasks[blockindex];

			int tmp = mask;
			int count = 0;
			while (tmp > 0) {
				count += tmp & 1;
				tmp >>= 1;
			}

			if (count == 1) {
				tmp = mask;
				int digit = 1;
				while ((tmp & 1) == 0) {
					digit++;
					tmp >>= 1;
				}

				sudoku[cur.first][cur.second] = digit;
				int digitmask = 1 << (digit - 1);
				rowmasks[cur.first] ^= digitmask;
				colmasks[cur.second] ^= digitmask;
				blockmasks[blockindex] ^= digitmask;

				updated = true;
			}
		}
	}

	printf("\n");
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			printf("%d ", sudoku[r][c]);
		}
		printf("\n");
	}

	for (int i = 0; i < blanklen; i++) {
		pair<int, int> cur = blanks[i];
		if (sudoku[cur.first][cur.second] != 0) continue;

		int bi = cur.first / 3;
		int bj = cur.second / 3;
		int blockindex = bj + bi * 3;
		int mask = rowmasks[cur.first] & colmasks[cur.second] & blockmasks[blockindex];

		printf("%d %d, %x\n", cur.first, cur.second, mask);
	}

	return 0;
}
