#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int highs[10004];
int lows[10004];

int lowspointer;

int result;

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		scanf("%d", highs + n);
	}
	for (int m = 0; m < M; m++) {
		scanf("%d", lows + m);
	}
	sort(highs, highs + N);
	sort(lows, lows + M);

	result += N; // farmer John can buy all high quality bales.

	for (int n = 0; n < N; n++) {
		if (lowspointer < M && lows[lowspointer] < highs[n]) {
			result++;
			lowspointer++;
		}
	}

	printf("%d\n", result);

	return 0;
}
