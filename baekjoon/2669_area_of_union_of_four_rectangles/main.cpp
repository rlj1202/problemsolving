#include <iostream>

bool grid[102][102];

int main() {
	for (int i = 0; i < 4; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int r = y1; r < y2; r++) {
			for (int c = x1; c < x2; c++) {
				grid[r][c] = true;
			}
		}
	}

	int area = 0;
	for (int r = 1; r <= 100; r++)
		for (int c = 1; c <= 100; c++)
			area += grid[r][c];

	printf("%d\n", area);

	return 0;
}
