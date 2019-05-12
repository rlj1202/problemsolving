#include <iostream>
#include <algorithm>

using namespace std;

struct Range { int start, end; };

bool operator< (const Range &a, const Range &b) {
	if (a.start == b.start) return a.end > b.end;
	return a.start < b.start;
}

int N, L;
int A, B;
Range ranges[1003];

int ridge[1000006];

int main() {
	// read input
	scanf("%d %d", &N, &L);
	scanf("%d %d", &A, &B);
	for (int n = 0; n < N; n++) {
		int s, e;
		scanf("%d %d", &s, &e);
		ranges[n] = {s, e};
	}
	sort(ranges, ranges + N);

	// numbering the ridge while merge overlapping ranges
	int id = 0;
	int last = 0;
	for (int n = 0; n < N; n++) {
		Range cur = ranges[n];
		
		if (last <= cur.start) id++;
		for (int i = max(last, cur.start); i < cur.end; i++)
			ridge[i] = id;
		last = cur.end;
	}

	// count sprinklers
	bool failed = false;
	int sprinklers = 0;

	int last_id = 0;
	int count = 0;
	for (int l = 0; l < L; l += 2) {
		if (ridge[l] != 0 && ridge[l + 1] != 0) {
			if (ridge[l] != ridge[l + 1]) {
				failed = true;
				break;
			}
		}

		int cur_id = max(ridge[l], ridge[l + 1]);

		if (last_id != cur_id) {
			if (last_id == 0) {
			} else {
			}

			last_id = cur_id;
			count = 0;
		}

		count++;
	}

	// print result
	if (!failed) printf("%d\n", sprinklers);
	else printf("%d\n", -1);

	return 0;
}
