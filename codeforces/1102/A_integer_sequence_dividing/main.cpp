#include <iostream>

int N;

int result;

int main() {
	scanf("%d", &N);

	if (N % 2 == 0) {
		if (N % 4 == 0) {
			result = 0;
		} else {
			result = 1;
		}
	} else {
		if (((N + 1) / 2) % 2 == 0) {
			result = 0;
		} else {
			result = 1;
		}
	}

	printf("%d\n", result);

	return 0;
}
