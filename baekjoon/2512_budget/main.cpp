#include <cstdio>
#include <algorithm>

using namespace std;

int claims[10004];
int maxclaim;

int main() {
	int N, M;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", claims + n);
		maxclaim = max(maxclaim, claims[n]);
	}
	scanf("%d", &M);

	int l = 0;
	int r = 1e5;
	int mid = (l + r) / 2;

	while (l < r) {
		int total = 0;
		for (int n = 0; n < N; n++) total += min(claims[n], mid);

		if (total <= M) l = mid;
		else r = mid - 1;
		mid = (l + r + 1) / 2;
	}

	printf("%d\n", min(mid, maxclaim));

	return 0;
}
