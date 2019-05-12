#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[5003];

int minCost[5003][5003];

int dp(int l, int r) {
	if (r - l <= 0) return 0;
	if (minCost[l][r] != 0) return minCost[l][r];

	if (arr[l] == arr[r]) {
		return dp(l + 1, r - 1);
	} else {
		return minCost[l][r] = min(dp(l + 1, r), dp(l, r - 1)) + 1;
	}
}

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++)
		scanf("%d", arr + n);

	printf("%d\n", dp(1, N));

	return 0;
}
