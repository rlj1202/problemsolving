#include <cstdio>
#include <algorithm>

using namespace std;

int scores[300005];

int range[20][300005];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", scores + n);
	}
	sort(scores, scores + N);

	int log = 0;
	int tmp = N;
	while (tmp >>= 1) log++;
	for (int n = 0; n < N; n++) {
		range[0][n] = scores[n] + (N - n);
	}
	for (int l = 1; l <= log; l++) {
		int len = 1 << l;
		int prev = 1 << (l - 1);

		for (int n = 0; n < N - len + 1; n++) {
			range[l][n] = max(range[l - 1][n], range[l - 1][n + prev]);
		}
	}

	int cnt = 0;

	for (int n = 0; n < N; n++) {
		int p = n + 1;
		int q = N - 1;
		int l = 0;
		int tmp = (q - p + 1);
		while (tmp >>= 1) l++;

		int rightmax = max(range[l][p], range[l][q - (1 << l) + 1]);
		if (scores[n] + N >= rightmax) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
