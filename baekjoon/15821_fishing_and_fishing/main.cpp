#include <cstdio>
#include <algorithm>

using namespace std;

long long distances[100005];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int n = 0; n < N; n++) {
		int P;
		scanf("%d", &P);

		long long maxdistance = 0;

		for (int p = 0; p < P; p++) {
			long long x, y;
			scanf("%lld %lld", &x, &y);

			maxdistance = max(maxdistance, x*x + y*y);
		}

		distances[n] = maxdistance;
	}

	sort(distances, distances + N);
	printf("%lld.00\n", distances[K - 1]);

	return 0;
}
