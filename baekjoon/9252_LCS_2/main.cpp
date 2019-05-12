#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char a[1003];
char b[1003];
int alen;
int blen;

int dp[1003][1003];
int back[1003][1003][2];

char result[1003];
int resultlen = 0;

int main() {
	scanf("%s %s", a + 1, b + 1);
	alen = strlen(a + 1);
	blen = strlen(b + 1);

	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;

				back[i][j][0] = i - 1;
				back[i][j][1] = j - 1;
			} else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];

					back[i][j][0] = i - 1;
					back[i][j][1] = j;
				} else {
					dp[i][j] = dp[i][j - 1];
					
					back[i][j][0] = i;
					back[i][j][1] = j - 1;
				}
			}
		}
	}


	printf("%d\n", dp[alen][blen]);
	int curi = alen;
	int curj = blen;
	while (curi != 0 && curj != 0) {
		if (a[curi] == b[curj]) result[resultlen++] = a[curi];
		int newi = back[curi][curj][0];
		int newj = back[curi][curj][1];
		curi = newi;
		curj = newj;
	}

	for (int i = resultlen - 1; i >= 0; i--) printf("%c", result[i]);
	printf("\n");

	return 0;
}
