#include <iostream>
#include <algorithm>

using namespace std;

struct Segment { int l, r; };

bool operator< (const Segment &a, const Segment &b) {
	if (a.r == b.r) return a.l < b.l;
	else return a.r < b.r;
}

int N;
Segment segments[100005];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int l, r;
		scanf("%d %d", &l, &r);
		segments[n] = {l, r};
	}
	sort(segments, segments + N);

	int count = 0;

	int last = 0;
	for (int n = 0; n < N; n++) {
		Segment cur = segments[n];

		if (last <= cur.l) {
			count++;
			last = cur.r;
		}
	}

	printf("%d\n", count);

	return 0;
}
