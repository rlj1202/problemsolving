#include <iostream>

struct Point { int x, y; };
struct Bound { Point a, b; };

Bound bb1, bb2, truck;

void readBound(Bound *bound) {
	int x1, x2;
	int y1, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	bound->a = {x1, y1};
	bound->b = {x2, y2};
}

int area(Bound *bound) {
	int width = bound->b.x - bound->a.x;
	int height = bound->b.y - bound->a.y;
	return width * height;
}

void sort(int *arr) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int intersection(Bound *A, Bound *B) {
	int width, height;

	if (A->b.x <= B->a.x || B->b.x <= A->a.x) {
		width = 0;
	} else {
		int tmp[4] = {A->a.x, A->b.x, B->a.x, B->b.x};
		sort(tmp);
		width = tmp[2] - tmp[1];
	}

	if (A->b.y <= B->a.y || B->b.y <= A->a.y) {
		height = 0;
	} else {
		int tmp[4] = {A->a.y, A->b.y, B->a.y, B->b.y};
		sort(tmp);
		height = tmp[2] - tmp[1];
	}

	return width * height;
}

int main() {
	readBound(&bb1);
	readBound(&bb2);
	readBound(&truck);

	int totalArea = 0;
	totalArea += area(&bb1);
	totalArea += area(&bb2);
	totalArea -= intersection(&bb1, &truck);
	totalArea -= intersection(&bb2, &truck);

	printf("%d\n", totalArea);

	return 0;
}
