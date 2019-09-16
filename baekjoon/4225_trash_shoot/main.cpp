#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Vector {
	int x, y;
	Vector operator- (Vector o) {
		return {x - o.x, y - o.y};
	}
	int cross(Vector o) {
		return x * o.y - y * o.x;
	}
	int dot(Vector o) {
		return x * o.x + y * o.y;
	}
	bool operator< (Vector o) {
		if (x == o.x) return y < o.y;
		else return x < o.x;
	}
	bool operator> (Vector o) {
		if (x == o.x) return y > o.y;
		else return x > o.x;
	}
};

Vector points[102];

Vector stack[102];
int top;

int ccw(Vector a, Vector b, Vector c) {
	return (c - b).cross(a - b);
}

int main() {
	int t = 0;
	while (++t) {
		int N;
		scanf("%d", &N);
		if (N == 0) break;

		for (int n = 0; n < N; n++) {
			int x, y;
			scanf("%d %d", &x, &y);
			points[n] = {x, y};
		}

		for (int n = 0; n < N; n++) {
			if (points[0] > points[n]) {
				swap(points[0], points[n]);
			}
		}
		Vector pivot = points[0];

		sort(points + 1, points + N, [pivot](Vector a, Vector b) -> bool {
				int ori = ccw(pivot, a, b);
				
				if (ori == 0) {
					int da = (a - pivot).dot(a - pivot);
					int db = (b - pivot).dot(b - pivot);
					return da < db;
				} else {
					return ori > 0;
				}
				});

		top = 0;
		stack[top++] = points[0];
		stack[top++] = points[1];

		for (int n = 2; n < N; n++) {
			Vector cur = points[n];

			while (top >= 2) {
				int ori = ccw(stack[top - 2], stack[top - 1], cur);
				if (ori <= 0) top--;
				else break;
			}

			stack[top++] = cur;
		}
		
		double result = 1e10;

		Vector prev = stack[top - 1];
		for (int i = 0; i < top; i++) {
			Vector cur = stack[i];

			Vector line = cur - prev;
			double linelen = sqrt(line.dot(line));

			double maxdist = 0;

			for (int j = 0; j < top; j++) {
				Vector toPoint = stack[j] - prev;

				long long area = line.cross(toPoint);

				double dist = area / linelen;
				maxdist = max(maxdist, dist);
			}

			result = min(result, maxdist);
			prev = cur;
		}

		result = ceil(result * 100) / 100; // 소수점 두자리에서 올림

		printf("Case %d: %.2f\n", t, result);
	}

	return 0;
}
