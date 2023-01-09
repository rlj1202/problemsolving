#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[10][2003];

int indices[2003];
int maxProfit;
int maxIndices[2003];

int getMaxProfit(int l, int r) {
	int tmp = r - l + 1;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;
	int len = 1 << log;

	return max(arr[log][l], arr[log][r - len + 1]);
}

void f(int day, int index, int profit) {
	if (day == K - 1) {
		int curProfit = profit + getMaxProfit(index, N - 1);

		if (maxProfit < curProfit) {
			maxProfit = curProfit;
			for (int k = 1; k < K; k++) maxIndices[k] = indices[k];
		}

		return;
	}

	for (int next = index + 1; next < N; next++) {
		int curProfit = getMaxProfit(index, next - 1);
		indices[day + 1] = next;
		f(day + 1, next, profit + curProfit);
	}
}

int main() {
	// read input
	scanf("%d %d", &N, &K);

	for (int n = 0; n < N; n++) {
		scanf("%d", arr[0] + n);
	}

	//
	int log = 0;
	int tmp = N;
	while ((tmp >>= 1) != 0) log++;

	for (int l = 1; l <= log; l++) {
		int cur = 1 << l;
		int prev = 1 << (l - 1);

		for (int n = 0; n < N - cur + 1; n++) {
			arr[l][n] = max(arr[l - 1][n], arr[l - 1][n + prev]);
		}
	}

	f(0, 0, 0);

	// print result
	printf("%d\n", maxProfit);

	maxIndices[K] = N;
	for (int k = 1; k <= K; k++) {
		printf("%d ", maxIndices[k] - maxIndices[k - 1]);
	}
	printf("\n");

	return 0;
}
