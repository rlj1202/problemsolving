#include <iostream>
#include <cstring>

using namespace std;

int N;

const int MASK = (1 << 10) - 1;
const int MOD = 1000000000;

int counts[100][10][MASK + 1];

int dp(int n, int digit, int mask) {
	if (n >= N) return mask == MASK;

	if (counts[n][digit][mask] != -1) return counts[n][digit][mask];

	int result = 0;
	if (digit - 1 >= 0) result += dp(n + 1, digit - 1, mask | (1 << digit));
	if (digit + 1 <= 9) result += dp(n + 1, digit + 1, mask | (1 << digit));
	result %= MOD;

	return counts[n][digit][mask] = result;
}

int main() {
	scanf("%d", &N);

	memset(counts, -1, sizeof(counts));

	int result = 0;
	for (int digit = 1; digit <= 9; digit++) {
		result += dp(0, digit, 1 << digit);
		result %= MOD;
	}

	printf("%d\n", result);

	//

	long long sum = 0;

	for (int n = 1; n <= 40; n++) {
		N = n;
		memset(counts, -1, sizeof(counts));

		int result = 0;
		for (int digit = 1; digit <= 9; digit++) {
			result += dp(0, digit, 1 << digit);
			result %= MOD;
		}

		sum += result;
	}
	printf("%lld\n", sum);


	return 0;
}
