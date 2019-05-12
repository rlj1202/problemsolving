#include <iostream>
#include <algorithm>

using namespace std;

int N;
int seq[1000006];

int dp[1000006];
int dplen;

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", seq + n);

	for (int n = 0; n < N; n++) {
		int cur = seq[n];

		int index = lower_bound(dp, dp + dplen, cur) - dp;
		dp[index] = cur;
		if (index >= dplen) dplen++;
	}

	printf("%d\n", dplen);

	return 0;
}
