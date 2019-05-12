#include <iostream>
#include <cstring>

using namespace std;

char a[103];
char b[103];
char c[103];

int dp[102][102];
int back[102][102][2];

void lcs(char *u, char *v, char *out) {
	int ulen = strlen(u + 1);
	int vlen = strlen(v + 1);

	for (int i = 1; i <= ulen; i++) {
		for (int j = 1; j <= vlen; j++) {
			if (u[i] == v[j]) {
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

	int outlen = dp[ulen][vlen];
	int i = 0;

	int curi = ulen;
	int curj = vlen;
	while (curi != 0 && curj != 0) {
		if (u[curi] == v[curj]) out[outlen - i++] = u[curi];
		int newi = back[curi][curj][0];
		int newj = back[curi][curj][1];
		curi = newi;
		curj = newj;
	}
	out[outlen + 1] = 0;
}

int main() {
	scanf("%s %s %s", a + 1, b + 1, c + 1);

	char tmp[103];
	lcs(a, b, tmp);

	char result[103];
	lcs(c, tmp, result);

	printf("\n\n%s\n%s\n", tmp + 1, result + 1);

	printf("%d\n", (int) strlen(result + 1));

	return 0;
}
