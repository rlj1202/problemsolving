#include <iostream>
#include <algorithm>

using namespace std;

int N;
int series[100005];
pair<int, int> sum[100005];

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		scanf("%d", series + n);
		sum[n].first = sum[n - 1].first + series[n];
		sum[n].second = n;
	}
	
	/* XXX */ //printf("\t"); for (int i = 1; i <= N; i++) printf("%d ", sum[i].first); printf("\n");

	sort(sum + 1, sum + 1 + N);

	/* XXX */ printf("\t"); for (int i = 0; i <= N; i++) printf("(%d [%d]) ", sum[i].first, sum[i].second); printf("\n");

	int maxsum = -2000000009;

	for (int l = 0; l <= N - 1; l++) {
		int r = N;
		while (l < r && sum[l].second > sum[r].second) r--;

		if (sum[l].second < sum[r].second) maxsum = max(maxsum, sum[r].first - sum[l].first);
	}

	printf("%d\n", maxsum);

	return 0;
}
