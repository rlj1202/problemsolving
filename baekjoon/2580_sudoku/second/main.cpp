#include <iostream>

struct Point { int r, c; };

int sudoku[9][9];

int rowmasks[9];
int colmasks[9];
int blkmasks[9];

Point blanks[81];
int blen;

bool fillblank(int index) {
	if (index == blen) return true;

	Point cur = blanks[index];

	int bi = cur.r / 3;
	int bj = cur.c / 3;
	int b = bj + bi * 3;

	int mask = rowmasks[cur.r] & colmasks[cur.c] & blkmasks[b];

	int digit = 1;
	while (mask > 0) {
		if ((mask & 1) == 1) {
			sudoku[cur.r][cur.c] = digit;

			int digitmask = 1 << (digit - 1);
			rowmasks[cur.r] ^= digitmask;
			colmasks[cur.c] ^= digitmask;
			blkmasks[b] ^= digitmask;

			bool result = fillblank(index + 1);

			if (result) return true;

			rowmasks[cur.r] ^= digitmask;
			colmasks[cur.c] ^= digitmask;
			blkmasks[b] ^= digitmask;
		}

		digit++;
		mask >>= 1;
	}

	return false;
}

int main() {
	// read input
	for (int r = 0; r < 9; r++)
		for (int c = 0; c < 9; c++) scanf("%d", &sudoku[r][c]);

	// make masks
	for (int i = 0; i < 9; i++) {
		int mask = (1 << 9) - 1;
		rowmasks[i] = mask;
		colmasks[i] = mask;
		blkmasks[i] = mask;
	}
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			int digit = sudoku[r][c];
			if (digit == 0) continue;

			int bi = r / 3;
			int bj = c / 3;
			int b = bj + bi * 3;

			int digitmask = ~(1 << (digit - 1));
			rowmasks[r] &= digitmask;
			colmasks[c] &= digitmask;
			blkmasks[b] &= digitmask;
		}
	}

	// find blanks and fill the blanks
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++)
			if (sudoku[r][c] == 0) blanks[blen++] = {r, c};
	}
	fillblank(0);

	// print result
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) printf("%d ", sudoku[r][c]);
		printf("\n");
	}

	return 0;
}
