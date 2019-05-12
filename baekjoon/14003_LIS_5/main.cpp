#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000006];
int linked[1000006];

int dp[1000006];
int dpindices[1000006];
int dplen;

int result[1000006];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", arr + n);
	
	for (int n = 0; n < N; n++) {
		int cur = arr[n];

		int index = lower_bound(dp, dp + dplen, cur) - dp;
		dp[index] = cur;
		dpindices[index] = n;
		if (index >= dplen) dplen++;

		if (index > 0) linked[n] = dpindices[index - 1];
		else linked[n] = -1;
	}

	printf("%d\n", dplen);
	int cur = dpindices[dplen - 1];
	int i = 0;
	while (cur != -1) {
		result[i++] = arr[cur];
		cur = linked[cur];
	}
	while (i--) printf("%d ", result[i]);
	printf("\n");

	return 0;
}
