#include <iostream>
#include <cmath>

using namespace std;

struct Vertex { long long x, y; };

int N;
Vertex vertices[10004];

long long ccw(Vertex a, Vertex b, Vertex c) {
	return a.x*b.y + b.x*c.y + a.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vertices[n] = {x, y};
	}

	long long area = 0;

	for (int n = 0; n < N; n++) {
		int m = (n + 1) % N;
		area += vertices[n].x * vertices[m].y;
		area -= vertices[n].y * vertices[m].x;
	}

	printf("%.1Lf\n", llabs(area) / 2.0L);

	return 0;
}
