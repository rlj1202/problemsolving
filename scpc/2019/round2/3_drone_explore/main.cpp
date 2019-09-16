#include <cstdio>
#include <algorithm>

using namespace std;

struct Line {
	int x, y;
	bool open;
	bool ceil;
	
	bool operator< (const Line &o) const {
		if (x == o.x) return open < o.open;
		return x < o.x;
	}
};

const int INF = 0x3f3f3f3f;

Line lines[400005];
int lineslen;

int main() {
	setbuf(stdout, NULL);

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int min_ceil = INF;
		int max_floor = 0;

		int result = 0;

		lineslen = 0;

		// read input
		int L, S, E;
		scanf("%d %d %d", &L, &S, &E);

		int A;
		scanf("%d", &A);
		int lastA = 0;
		for (int a = 0; a < A; a++) {
			int len, height;
			scanf("%d %d", &len, &height);

			min_ceil = min(min_ceil, height);

			lines[lineslen++] = {lastA, height, true, true};
			lines[lineslen++] = {lastA + len, height, false, true};

			lastA += len;
		}

		int B;
		scanf("%d", &B);
		int lastB = 0;
		for (int b = 0; b < B; b++) {
			int len, height;
			scanf("%d %d", &len, &height);

			max_floor = max(max_floor, height);

			lines[lineslen++] = {lastB, height, true, false};
			lines[lineslen++] = {lastB + len, height, false, false};

			lastB += len;
		}

		sort(lines, lines + lineslen);

		// line sweeping
		int cur_ceil_height = 0;
		int cur_floor_height = 0;
		int prev_x = 0;
		int cur_x = 0;

		for (int i = 0; i < lineslen; i++) {
			result += (cur_x - prev_x) * (1);

			Line line = lines[i];

			prev_x = cur_x;
			cur_x = line.x;

			if (line.ceil) {
				cur_ceil_height = line.y;
			} else {
				cur_floor_height = line.y;
			}
		}

		// print result
		printf("Case #%d\n", t);
		printf("%d\n", result);
	}

	return 0;
}
