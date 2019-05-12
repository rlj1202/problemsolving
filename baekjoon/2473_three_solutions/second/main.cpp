#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
long long sols[5003];

int main() {
	// init
	memset(sols, 0x3f, sizeof(sols));

	// read input
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%lld", sols + n);

	// sort input
	sort(sols, sols + N);

	long long minsum = sols[0] + sols[1] + sols[2];
	int a = 0;
	int b = 1;
	int c = 2;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			long long delta = sols[i] + sols[j];

			int k = lower_bound(sols + j + 1, sols + N, -delta) - sols;

			if (sols[k] != -delta) {
				if (j < k - 1 && llabs(delta + sols[k]) > llabs(delta + sols[k - 1])) k--;
			}

			if (llabs(minsum) > llabs(delta + sols[k])) {
				minsum = delta + sols[k];
				a = i;
				b = j;
				c = k;
			}
		}
	}

	// print result
	printf("%lld %lld %lld\n", sols[a], sols[b], sols[c]);

	return 0;
}
