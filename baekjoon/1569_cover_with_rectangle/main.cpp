#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int x[102];
int y[102];
int minX, maxX;
int minY, maxY;
int width, height;
int top, bottom, left, right;

int main() {
	scanf("%d", &N);

	scanf("%d %d", x + 1, y + 1);
	minX = maxX = x[1];
	minY = maxY = y[1];
	for (int n = 2; n <= N; n++) {
		scanf("%d %d", x + n, y + n);

		minX = min(minX, x[n]);
		maxX = max(maxX, x[n]);
		minY = min(minY, y[n]);
		maxY = max(maxY, y[n]);
	}

	for (int n = 1; n <= N; n++) {
		bool fail = true;
		if (x[n] == minX) {
			if (minY <= y[n] && y[n] <= maxY)
				fail = false;
			if (y[n] != minY && y[n] != maxY)
				left++;
		}
		if (x[n] == maxY) {
			if (minY <= y[n] && y[n] <= maxY)
				fail = false;
			if (y[n] != minY && y[n] != maxY)
				right++;
		}
		if (y[n] == minY) {
			if (minX <= x[n] && x[n] <= maxX)
				fail = false;
			if (x[n] != minX && x[n] != maxX)
				bottom++;
		}
		if (y[n] == maxY) {
			if (minX <= x[n] && x[n] <= maxX)
				fail = false;
			if (x[n] != minX && x[n] != maxX)
				top++;
		}

		if (fail) {
			printf("-1\n");
			return 0;
		}
	}
	
	width = maxX - minX;
	height = maxY - minY;

	if (width != height) {
		bool fail = false;
		if (width > height) {
			if (top != 0 && bottom != 0) {
				fail = true;
			}
		} else {
			if (left != 0 && right != 0) {
				fail = true;
			}
		}

		if (fail) {
			printf("-1\n");
			return 0;
		}
	}

	printf("%d\n", width);

	return 0;
}
