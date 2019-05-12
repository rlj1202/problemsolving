#include <iostream>
#include <algorithm>

using namespace std;

int N;
int sum[20][100005];

int findmax(int l, int r) {
	int tmp = r - l + 1;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;

	int len = 1 << log;

	return max(sum[log][l], sum[log][r - len + 1]);
}

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		int value;
		scanf("%d", &value);
		sum[0][n] = sum[0][n - 1] + value;
	}

	int tmp = N;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;

	for (int l = 1; l <= log; l++) {
		int len = 1 << l;
		int prev = 1 << (l - 1);

		for (int n = 1; n <= N - len + 1; n++) {
			sum[l][n] = max(sum[l - 1][n], sum[l - 1][n + prev]);
		}
	}

	int maxsum = sum[0][1];

	for (int l = 0; l <= N - 1; l++) {
		int left = sum[0][l];
		int right = findmax(l + 1, N);

		maxsum = max(maxsum, right - left);
	}

	printf("%d\n", maxsum);

	return 0;
}
