#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int W, L;
char S[302];
char words[602][30];
int wordlens[602];

int dp[302];

int main() {
	scanf("%d %d", &W, &L);
	scanf("%s", S);
	for (int w = 0; w < W; w++) {
		scanf("%s", words[w]);
		wordlens[w] = strlen(words[w]);
	}

	for (int r = 0; r <= L; r++) {
		dp[r] = r;

		for (int w = 0; w < W; w++) {
			int wordpointer = 0;
			int l = r;

			while (wordpointer < wordlens[w] && l > 0) {
				if (S[--l] == words[w][wordlens[w] - wordpointer - 1])
					wordpointer++;
			}

			if (wordpointer == wordlens[w]) {
				dp[r] = min(dp[r], dp[l] + (r - l) - wordlens[w]);
			}
		}
	}

	printf("%d\n", dp[L]);

	return 0;
}
