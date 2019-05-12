#include <iostream>
#include <algorithm>

using namespace std;

struct Detector { int pos, count; };

bool operator< (const Detector &a, const Detector &b) {
	return a.pos < b.pos;
}

int N, M;
Detector detectors[100005];

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		int pos, count;
		scanf("%d %d", &pos, &count);
		detectors[n] = {pos, count};
	}
	sort(detectors, detectors + N);

	long long count = 0;

	int last = 0;
	for (int n = 0; n <= N; n++) {
		int cur = detectors[n].count;
		if (last > cur) count += last - cur;
		last = cur;
	}

	printf("%lld\n", count);

	return 0;
}
