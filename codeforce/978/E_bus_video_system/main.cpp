#include <iostream>
#include <algorithm>

using namespace std;

int N, W;
int deltaSum[1003];

int minSum;
int maxSum;

int main() {
	// read input
	scanf("%d %d", &N, &W);

	for (int n = 1; n <= N; n++) {
		int value;
		scanf("%d", &value);
		deltaSum[n] = deltaSum[n - 1] + value;

		minSum = min(minSum, deltaSum[n]);
		maxSum = max(maxSum, deltaSum[n]);
	}

	// print result
	printf("%d\n", max(0, W - maxSum + minSum + 1));

	return 0;
}
