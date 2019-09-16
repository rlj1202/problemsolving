#include <cstdio>

int N, M;
int accepts[102];
int scoreboard[102][12];

int remains[102];
bool solved[12];

bool result;

int main() {
	// read input
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		scanf("%d", accepts + n);
		remains[n] = accepts[n];

		for (int m = 1; m <= M; m++) {
			scanf("%d", &scoreboard[n][m]);
			if (scoreboard[n][m] == 1) {
				remains[n]--;
				solved[m] = true;
			}
		}
	}

	result = true;

	for (int n = 1; n <= N; n++) {
		if (!accepts[n] || accepts[n] == M) {
			result = false;
			break;
		}
	}

	for (int n = N; n >= 1; n--) {
		for (int m = 1; m <= M; m++) {
			if (scoreboard[n][m] != -1) continue;
			if (solved[m]) continue;

			if (remains[n]) {
				scoreboard[n][m] = 1;
				remains[n]--;
				solved[m] = true;
			}
		}
	}

	for (int m = 1; m <= M; m++) {
		if (!solved[m]) {
			result = false;
			break;
		}
	}

	// print result
	printf("%s\n", result ? "YES" : "NO");

	return 0;
}
