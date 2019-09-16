#include <cstdio>

struct Mine { int x, y, w; };

int N;
Mine mines[3003];

int main() {
	// read input
	// O(N)
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		mines[n] = {x, y, w};
	}

	// print result
	printf("%lld\n", 0LL);

	return 0;
}
