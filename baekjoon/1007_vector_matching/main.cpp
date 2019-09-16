#include <cstdio>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
	long long x, y;

	Point() : Point(0, 0) {}
	Point(long long x, long long y) : x(x), y(y) {}

	Point operator+ (const Point &p) {
		return {x + p.x, y + p.y};
	}
	Point operator- (const Point &p) {
		return {x - p.x, y - p.y};
	}
	double len() {
		return sqrt(x*x + y*y);
	}
};

Point points[22];

double minsum(Point &sum, int cur, int count, int max, Point accum) {
	if (count == max / 2) {
		Point result = sum - accum - accum;
		return result.len();
	}

	double minvalue = numeric_limits<double>::max();

	for (int i = cur; i < max; i++) {
		double result = minsum(sum, i + 1, count + 1, max, accum + points[i]);
		minvalue = min(minvalue, result);
	}

	return minvalue;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		Point sum;

		for (int n = 0; n < N; n++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[n] = {x, y};
			sum = sum + points[n];
		}

		double result = minsum(sum, 0, 0, N, Point());

		printf("%.12f\n", result);
	}

	return 0;
}
