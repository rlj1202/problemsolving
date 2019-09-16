#include <cstdio>
#include <cstring>

char digits[7];
int digitslen;

int result;

void dfs(int remain_moves) {
	if (remain_moves) {
		for (int i = 0; i < digitslen - 1; i++) {
			for (int j = i + 1; j < digitslen; j++) {
				int tmp;

				tmp = digits[i];
				digits[i] = digits[j];
				digits[j] = tmp;

				dfs(remain_moves - 1);

				tmp = digits[i];
				digits[i] = digits[j];
				digits[j] = tmp;
			}
		}
	} else {
		int val = 0;

		int i = 0;
		while (digits[i]) {
			val *= 10;
			val += digits[i] - '0';
			i++;
		}

		if (result < val) result = val;
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%s %d", digits, &N);
		digitslen = strlen(digits);

		dfs(N);

		printf("#%d %d\n", t, result);
	}

	return 0;
}
