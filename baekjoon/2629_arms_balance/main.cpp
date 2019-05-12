#include <iostream>
#include <algorithm>

using namespace std;

const static int WEIGHTS_MAX = 50;
const static int MARBLE_MAX = 55000;

int W, T;
int weights[WEIGHTS_MAX];
int dp[WEIGHTS_MAX][MARBLE_MAX + 5];

int main() {
	scanf("%d", &W);
	for (int w = 1; w <= W; w++) {
		scanf("%d", weights + w);
	}
	sort(weights + 1, weights + W + 1);

	for (int w = 1; w <= W; w++) {
		int weight = weights[W - w + 1];

		dp[w][weight] |= 1;

		for (int i = 1; i <= MARBLE_MAX; i++) {
			if (dp[w - 1][i] == 1) {
				dp[w][i] |= 1;
				if (i - weight > 0) dp[w][i - weight] |= 1;
				if (i + weight <= MARBLE_MAX) dp[w][i + weight] |= 1;
			}
		}
	}

	printf("################################################################################\n");
	printf("      ");
	for (int i = 1; i <= 37; i++) {
		printf("%3d", i);
	}
	printf("\n");
	for (int w = 1; w <= W; w++) {
		int weight = weights[W - w + 1];

		printf("%3d : ", weight);

		for (int i = 1; i <= 37; i++) {
			int value = dp[w][i];
			printf("%3c", value ? 'Y' : '.');
		}
		printf("\n");
	}
	printf("################################################################################\n");

	scanf("%d", &T);

	while (T--) {
		int marble;
		scanf("%d", &marble);

		int result = dp[W][marble];
		printf("%c ", result ? 'Y' : 'N');
	}

	return 0;
}
