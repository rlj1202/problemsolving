#define _USE_MATH_DEFINES

#include <cstdio>
#include <cmath>

struct Obstacle {
	int l, r, h;
};

Obstacle obstacles[1003];

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int R, S, E, N;
		scanf("%d %d %d %d", &R, &S, &E, &N);
		for (int n = 0; n < N; n++) {
			int l, r, h;
			scanf("%d %d %d", &l, &r, &h);
			obstacles[n] = {l, r, h};
		}

		long double result = 0;

		int prev = S - R;
		for (int n = 0; n < N; n++) {
			Obstacle cur = obstacles[n];

			result += cur.l - prev - 2*R; // distance rolled between the two obstacles
			result += cur.r - cur.l; // distance rolled on an obstacle

			if (cur.h >= R) {
				result += 2*cur.h - 2*R; // distance rolled up and down on an obstacle
				result += M_PI * (long double) R; // distance rolled on corners of obstacle
			} else {
				long double theta = acos(1 - cur.h/(long double) R);
				result += 2*R*(1 - sin(theta)); // move forward little bit
				result += 2*R*theta; // length of the curve
				// mul 2 to twice the value
			}

			prev = cur.r;
		}
		result += E - prev - R; // roll up to the end

		printf("Case #%d\n", t);
		printf("%.12Lf\n", result);
	}

	return 0;
}
