#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Vector {
	long long x, y;
	Vector operator- (Vector o) {
		return {x - o.x, y - o.y};
	}
	Vector operator+ (Vector o) {
		return {x + o.x, y + o.y};
	}
	long long dot(Vector o) {
		return x * o.x + y * o.y;
	}
	long long cross(Vector o) {
		return x * o.y - y * o.x;
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

Vector points[200005];

Vector stack[200005];
int top;

long long ccw(Vector a, Vector b, Vector c) {
	return (c - b).cross(a - b);
}

double sine_theta(Vector a, Vector b) {
	return a.cross(b) / sqrt(a.dot(a)) / sqrt(b.dot(b));
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// read input
		int N;
		scanf("%d", &N);
		for (int n = 0; n < N; n++) {
			long long x, y;
			scanf("%lld %lld", &x, &y);
			points[n] = {x, y};
		}

		// get pivot
		for (int n = 0; n < N; n++) {
			if (points[0] > points[n]) {
				swap(points[0], points[n]);
			}
		}
		Vector pivot = points[0];

		// sort points
		sort(points + 1, points + N, [pivot](Vector a, Vector b) -> bool {
				long long ori = ccw(pivot, a, b);

				if (ori == 0) {
					long long da = (a - pivot).dot(a - pivot);
					long long db = (b - pivot).dot(b - pivot);
					return da < db;
				} else {
					return ori > 0;
				}
				});

		// do graham scan
		top = 0;
		stack[top++] = points[0];
		stack[top++] = points[1];

		for (int n = 2; n < N; n++) {
			Vector cur = points[n];

			while (top >= 2) {
				long long ori = ccw(stack[top - 2], stack[top - 1], cur);
				if (ori <= 0) top--;
				else break;
			}

			stack[top++] = cur;
		}

		// rotating calipers
		long long maxdist2 = 0;
		int maxa;
		int maxb;

		int a = 0;
		int b = 0;
		Vector va = {0, -1};
		Vector vb = {0, 1};

		for (int i = 0; i < top; i++) {
			if (stack[a] > stack[i]) a = i;
			if (stack[b] < stack[i]) b = i;
		}

		for (int i = 0; i < top; i++) {
			// update distance
			Vector delta = stack[a] - stack[b];
			long long dist2 = delta.dot(delta);
			if (maxdist2 < dist2) {
				maxdist2 = dist2;
				maxa = a;
				maxb = b;
			}

			// rotate calipers
			int na = (a + 1) % top;
			int nb = (b + 1) % top;
			double a_sine_theta = sine_theta(va, stack[na] - stack[a]);
			double b_sine_theta = sine_theta(vb, stack[nb] - stack[b]);

			if (a_sine_theta < b_sine_theta) {
				Vector move = stack[na] - stack[a] - va;
				va = va + move;
				vb = vb - move;
				a = na;
			} else {
				Vector move = stack[nb] - stack[b] - vb;
				vb = vb + move;
				va = va - move;
				b = nb;
			}
		}

		// print result
		printf("%lld %lld %lld %lld\n",
				stack[maxa].x, stack[maxa].y,
				stack[maxb].x, stack[maxb].y);
	}

	return 0;
}
