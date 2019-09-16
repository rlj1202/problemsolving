#include <cstdio>
#include <algorithm>

using namespace std;

struct Vector {
	long long x, y;
	Vector operator- (Vector o) { return {x - o.x, y - o.y}; }
	long long cross(Vector o) { return x * o.y - y * o.x; }
	long long dot(Vector o) { return x * o.x + y * o.y; }
	bool operator< (Vector o) {
		if (x == o.x) return y < o.y;
		return x < o.x;
	}
	bool operator> (Vector o) {
		if (x == o.x) return y > o.y;
		return x > o.x;
	}
};

Vector points[100005];
Vector stack[100005];
int stacksize;

long long ccw(Vector a, Vector b, Vector c) {
	return (c - b).cross(a - b);
}

int main() {
	// read input
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		points[n] = {x, y};
	}

	// get pivot
	for (int n = 0; n < N; n++)
		if (points[0] > points[n])
			swap(points[0], points[n]);
	Vector pivot = points[0];

	// sort the other points in ccw order
	sort(points + 1, points + N, [&pivot](Vector &a, Vector &b) -> bool {
			long long ori = ccw(pivot, a, b);
			if (ori > 0) {
				return true;
			} else if (ori == 0) {
				long long da = (a - pivot).dot(a - pivot);
				long long db = (b - pivot).dot(b - pivot);
				return da < db;
			}
			return false;
			});

	// do gramham scan
	stack[stacksize++] = points[0];
	stack[stacksize++] = points[1];

	for (int n = 2; n < N; n++) {
		while (stacksize >= 2) {
			if (ccw(stack[stacksize - 2], stack[stacksize - 1], points[n]) <= 0) stacksize--;
			else break;
		}
		stack[stacksize++] = points[n];
	}

	// print result
	printf("%d\n", stacksize);

	return 0;
}
