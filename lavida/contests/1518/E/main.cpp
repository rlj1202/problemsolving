#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);

		int rmin = 0;
		int rmax = 0;

		for (int n = 1; n <= N; n++) {
			int pmin = 0;
			int pmax = 0;
			for (int m = 1; m <= M; m++) {
				int a, b;
				scanf("%d %d", &a, &b);
				pmin += a;
				pmax += b;
			}
			rmin = max(rmin, pmin);
			rmax = max(rmax, pmax);
		}
		printf("%d %d\n", rmin, rmax);
	}

	return 0;
}
