#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Number {
	int digits[35];
	int len;

	Number() : Number(0) {
	}

	Number(long long n) {
		memset(digits, 0, sizeof(digits));
		len = 0;
		while (n > 0) {
			digits[len++] = n % 10;
			n = n / 10;
		}
	}

	Number operator+(const Number &a) {
		Number n;
		n.len = max(len, a.len);

		for (int i = 0; i < n.len; i++)
			n.digits[i] = digits[i] + a.digits[i];

		for (int i = 0; i < n.len; i++) {
			int value = n.digits[i];
			n.digits[i] = value % 10;
			n.digits[i+1] += value / 10;
		}
		if (n.digits[n.len] > 0) n.len++;

		int carry;
		while ((carry = n.digits[n.len - 1] / 10)) {
			int remainder = n.digits[n.len - 1] % 10;
			n.digits[n.len - 1] = remainder;
			n.digits[n.len++] = carry;
		}

		return n;
	}
};

int N, M;
Number tri[102][102];

void printNumber(const Number &n) {
	for (int i = 0; i < n.len; i++)
		printf("%d", n.digits[n.len - i - 1]);
}

int main() {
	scanf("%d %d", &N, &M);
	if (M > N / 2) M = N - M;

	tri[0][0] = 1;
	for (int n = 1; n <= N; n++) {
		tri[n][0] = 1;
		tri[n - 1][n] = 0;

		for (int m = 1; m < n + 1; m++)
			tri[n][m] = tri[n - 1][m - 1] + tri[n - 1][m];
	}

	printNumber(tri[N][M]);
	printf("\n");

	return 0;
}
