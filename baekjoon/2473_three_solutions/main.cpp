#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long sols[5003];

int main() {
	// read input and sort it
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%lld", sols + n);
	sort(sols, sols + N);

	/* XXX */ for (int n = 0; n < N; n++) printf("%lld ", sols[n]); printf("\n");

	// find three solutions!
	int l = 0;
	int r = N - 1;
	int m = (l + r) / 2;

	long long minsum = sols[l] + sols[m] + sols[r];
	int a = l;
	int b = m;
	int c = r;

	while (r - l > 1) {
		long long delta = sols[l] + sols[r];

		int range = r - l + 1;
		m = lower_bound(sols + l + 1, sols + l + range - 2, -delta) - sols;

		if (-delta != sols[m])
			if (l < m - 1 && llabs(delta + sols[m]) > llabs(delta + sols[m - 1])) m--;

		if (llabs(minsum) > llabs(delta + sols[m])) {
			minsum = delta + sols[m];
			a = l;
			b = m;
			c = r;
		}

		if (llabs(sols[l]) > llabs(sols[r])) l++;
		else r--;
	}

	// print result
	printf("%lld %lld %lld\n", sols[a], sols[b], sols[c]);
	
	return 0;
}
