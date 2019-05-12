#include <iostream>

int x[3];
int y[3];

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	return ax*by + bx*cy + cx*ay - ay*bx - by*cx - cy*ax;
}

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", x + i, y + i);
	}

	int result = ccw(
			x[0], y[0],
			x[1], y[1],
			x[2], y[2]);

	if (result > 0) printf("%d\n", 1);
	else if (result < 0) printf("%d\n", -1);
	else printf("%d\n", 0);

	return 0;
}
