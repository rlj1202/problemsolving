#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int B, G, N;
	scanf("%d %d %d", &B, &G, &N);

	int maxBoys = min(B, N);
	int maxGirls = min(G, N);
	int minBoys = N - maxGirls;
	int minGirls = N - maxBoys;

	int count = 0;

	for (int n = 0; n <= N; n++) {
		int boys = n;
		int girls = N - n;

		if (minBoys <= boys && boys <= maxBoys &&
				minGirls <= girls && girls <= maxGirls) {
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
