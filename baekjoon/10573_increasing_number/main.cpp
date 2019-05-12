#include <iostream>
#include <cstring>

using namespace std;

int T;

unsigned long long dp[81][10]; // dp[len][digit]

unsigned long long f(int len, int digit) {
	if (dp[len][digit] != 0) return dp[len][digit];
	if (len == 1) return 1;

	unsigned long long result = 0;
	for (int d = digit; d < 10; d++) {
		result += f(len - 1, d);
	}
	return dp[len][digit] = result;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		char raw[80 + 1];
		scanf("%s", raw);

		int digit_len = strlen(raw);
		int digits[80 + 2];
		digits[0] = 0;
		for (int i = 0; i < digit_len; i++) digits[i + 1] = raw[i] - '0';

		bool failed = false;

		unsigned long long result = 0;
		for (int i = 0; i < digit_len; i++) {
			int d;
			for (d = digits[i]; d < digits[i + 1]; d++)
				result += f(digit_len - i, d);

			if (d != digits[i + 1]) {
				failed = true;
				break;
			}
		}

		if (!failed) printf("%llu\n", result);
		else printf("%d\n", -1);
	}

	return 0;
}
