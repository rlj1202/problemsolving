#include <iostream>
#include <algorithm>

using namespace std;

int C, B;
int calories[30];

int dp[30][40004];

int main() {
	scanf("%d %d", &C, &B);
	for (int b = 1; b <= B; b++) {
		scanf("%d", calories + b);
	}

	dp[0][0] = 1;
	for (int b = 1; b <= B; b++) {
		int cur = calories[b];

		for (int c = 0; c <= C; c++) {
			if (c >= cur && dp[b - 1][c - cur] == 1) dp[b][c] = 1;
			if (dp[b - 1][c] == 1) dp[b][c] = 1;
		}
	}

	int max_calories = C;
	while (dp[B][max_calories] == 0) max_calories--;

	printf("%d\n", max_calories);

	return 0;
}
