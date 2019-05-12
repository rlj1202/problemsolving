#include <iostream>
#include <algorithm>

using namespace std;

struct Segment { int l, r, index; };

bool operator< (const Segment &a, const Segment &b) {
	return a.l < b.l;
}

int T;

int N;
Segment segments[100005];

int groups[100005];

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		for (int n = 0; n < N; n++) {
			int l, r;
			scanf("%d %d", &l, &r);

			segments[n] = {l, r, n};
		}
		sort(segments, segments + N);

		int last = segments[0].r;
		int group = 0;
		bool success = false;

		for (int n = 0; n < N; n++) {
			Segment cur = segments[n];
			
			if (last < cur.l) {
				group = !group;
				success = true;
			}

			groups[cur.index] = group + 1;
			last = max(last, cur.r);
		}

		if (success) {
			for (int i = 0; i < N; i++) printf("%d ", groups[i]);
			printf("\n");
		} else {
			printf("%d\n", -1);
		}
	}

	return 0;
}
