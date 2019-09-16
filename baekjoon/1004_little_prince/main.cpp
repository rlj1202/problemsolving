#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point { int x, y; };
struct Circle {
	int x, y, radius;
	bool contains(Point p) {
		int deltax = x - p.x;
		int deltay = y - p.y;
		int distsquare = deltax * deltax + deltay * deltay;
		return distsquare < radius * radius;
	}
};

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		Point s, e;
		int N;
		Circle circles[52];

		scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);
		scanf("%d", &N);
		for (int n = 0; n < N; n++)
			scanf("%d %d %d", &circles[n].x, &circles[n].y, &circles[n].radius);

		int result = 0;

		for (int n = 0; n < N; n++) {
			if (circles[n].contains(s) || circles[n].contains(e)) result++;
			if (circles[n].contains(s) && circles[n].contains(e)) result--;
		}

		printf("%d\n", result);
	}

	return 0;
}
