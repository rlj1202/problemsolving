#include <cstdio>
#include <algorithm>

using namespace std;

struct Point { int x, y; };

Point points[202];

bool slope_chk[4003][4003];

int result;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x, y;
		scanf("%d %d", &x, &y);
		points[n] = {x, y};
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int dx = points[i].x - points[j].x;
			int dy = points[i].y - points[j].y;

			int div = gcd(abs(dx), abs(dy));
			if (div == 0) continue;
			dx /= div;
			dy /= div;

			if (dx == 0) {
				dy = 1;
			} else if (dy == 0) {
				dx = 1;
			}
			if (dx < 0) {
				dx *= -1;
				dy *= -1;
			}

			if (!slope_chk[dx + 2000][dy + 2000]) {
				slope_chk[dx + 2000][dy + 2000] = true;
				result++;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
