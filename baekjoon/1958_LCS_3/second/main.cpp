#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char a[103];
char b[103];
char c[103];
int alen;
int blen;
int clen;

int dp[103][103][103];

int main() {
	scanf("%s %s %s", a + 1, b + 1, c + 1);
	alen = strlen(a + 1);
	blen = strlen(b + 1);
	clen = strlen(c + 1);

	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			for (int k = 1; k <= clen; k++) {
				if (a[i] == b[j] && b[j] == c[k]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				} else {
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
				}
			}
		}
	}

	printf("%d\n", dp[alen][blen][clen]);

	return 0;
}
