#include <cstdio>
#include <algorithm>

using namespace std;

int colors[250005];

long long left[250005];
long long right[250005];

int main() {
	int N;
	long long C;
	scanf("%d %lld", &N, &C);
	for (int n = 0; n < N; n++) {
		scanf("%d", colors + n);
	}

	for (int n = 1; n < N; n++) {
		long long count = colors[n - 1] - colors[n];
		if (count < 0) count += C;
		left[n] = left[n - 1] + count;
	}
	for (int n = N - 2; n >= 0; n--) {
		long long count = colors[n + 1] - colors[n];
		if (count < 0) count += C;
		right[n] = right[n + 1] + count;
	}

	long long mincount = 0x3f3f3f3f3f3f3f3f;
	int button;
	for (int n = 0; n < N; n++) {
		long long count = max(left[n], right[n]);
		if (mincount > count) {
			mincount = count;
			button = n;
		}
	}

	printf("%d\n", button + 1);
	printf("%lld\n", mincount);

	return 0;
}
