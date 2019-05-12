#include <iostream>
#include <algorithm>

using namespace std;

struct Interval { int l, r; };

bool operator< (const Interval &a, const Interval &b) {
	if (a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}

int N, T;
Interval intervals[25004];

Interval stack[25004];
int stacksize;

int main() {
	scanf("%d %d", &N, &T);
	for (int n = 0; n < N; n++) {
		int l, r;
		scanf("%d %d", &l, &r);
		intervals[n] = {l, r};
	}
	sort(intervals, intervals + N);

	bool valid = true;
	for (int n = 0; n < N; n++) {
		Interval cur = intervals[n];

		if (stacksize && cur.r <= stack[stacksize - 1].r) continue;

		if (stacksize && stack[stacksize - 1].r + 1 < cur.l) {
			valid = false;
			break;
		}

		while (stacksize > 1 && cur.l <= stack[stacksize - 2].r + 1) stacksize--;

		stack[stacksize++] = cur;
	}

	if (stacksize && stack[0].l > 1) valid = false;
	if (stacksize && stack[stacksize - 1].r < T) valid = false;

	if (valid) printf("%d\n", stacksize);
	else printf("%d\n", -1);

	return 0;
}
