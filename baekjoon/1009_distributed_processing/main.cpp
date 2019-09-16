#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int result = 1;
		for (int i = 0; i < b; i++) {
			result *= a;
			result %= 10;
		}
		if (result == 0) result = 10;
		printf("%d\n", result);
	}

	return 0;
}
