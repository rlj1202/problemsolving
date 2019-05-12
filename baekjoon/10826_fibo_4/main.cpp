#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Number {
	int digits[2500];
	int len;

	Number() {
		memset(digits, 0, sizeof(digits));
		len = 0;
	}

	Number(int n) : Number() {
		while (n > 0) {
			digits[len++] = n % 10;
			n /= 10;
		}
	}

	Number operator+ (const Number &n) {
		Number result;
		result.len = max(len, n.len);

		for (int i = 0; i < result.len; i++) {
			int value = result.digits[i] + digits[i] + n.digits[i];
			result.digits[i] = value % 10;
			result.digits[i + 1] = value / 10;
		}

		if (result.digits[result.len] != 0) result.len++;

		while (result.digits[result.len - 1] >= 10) {
			int value = result.digits[result.len - 1];
			result.digits[result.len - 1] = value % 10;
			result.digits[result.len] = value / 10;
			result.len++;
		}

		return result;
	}
};

int N;

void printNumber(Number n) {
	if (n.len == 0) printf("0");
	for (int i = 0; i < n.len; i++) {
		printf("%d", n.digits[n.len - i - 1]);
	}
}

int main() {
	scanf("%d", &N);

	Number a = 0;
	Number b = 1;

	while (N-- > 0) {
		Number c = a + b;
		a = b;
		b = c;
	}

	printNumber(a);
	printf("\n");

	return 0;
}
