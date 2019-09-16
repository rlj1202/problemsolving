#include <cstdio>
#include <algorithm>

using namespace std;

struct Cow { int idx, a, b; };

Cow cows[50004];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cows[n] = {n, a, b};
	}
	sort(cows, cows + N, [](const Cow &a, const Cow &b) {
			return a.a < b.a;
			});
	sort(cows + N - K, cows + N, [](const Cow &a, const Cow &b) {
			return a.b < b.b;
			});

	printf("%d\n", cows[N - 1].idx + 1);

	return 0;
}
