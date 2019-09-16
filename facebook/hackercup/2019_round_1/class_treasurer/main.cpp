#include <cstdio>
#include <cmath>

const int MOD = 1e9 + 7;

int power[1000006];
char str[1000006];

int main() {
	int T;

	power[0] = 1;
	for (int i = 1; i < 1000006; i++) {
		power[i] = power[i - 1] << 1;
		power[i] %= MOD;
	}

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N, K;
		int result = 0;

		scanf("%d %d", &N, &K);
		scanf("%s", str);

		for (int i = N - 1; i >= 0; i--) {
			int delta = 0;

			for (int j = i; j >= 0; j--) {
				char c = str[j];

				if (c == 'A') {
					delta--;
				} else { // c == 'B'
					delta++;
				}

				if (delta > K) {
					result += power[j + 1];
					result %= MOD;

					delta -= 2;
					str[j] = 'A';
				}
			}
		}

		printf("Case #%d: %d\n", t, result);
	}

	return 0;
}
