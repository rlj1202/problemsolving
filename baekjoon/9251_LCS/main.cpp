#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char a[1003];
char b[1003];
int alen;
int blen;

int dp[1003][1003];

int main() {
	scanf("%s %s", a + 1, b + 1);
	alen = strlen(a + 1);
	blen = strlen(b + 1);

	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			int prevmax = dp[i - 1][j - 1] + (a[i] == b[j]);
			prevmax = max(prevmax, dp[i - 1][j]);
			prevmax = max(prevmax, dp[i][j - 1]);

			dp[i][j] = prevmax;
		}
	}

	printf("%d\n", dp[alen][blen]);

	return 0;
}
