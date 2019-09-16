#include <cstdio>

int count[10];

int main() {
	int N;
	scanf("%d", &N);

	bool relative = true;

	while (N) {
		int digit = N % 10;
		count[digit]++;
		N /= 10;

		switch (digit) {
			case 2: case 0: case 1: case 8:
				break;
			default:
				relative = false;
				break;
		}
	}

	int result;

	if (relative) {
		if (count[2] && count[0] && count[1] && count[8]) {
			if (count[2] == count[0] && count[0] == count[1] &&
					count[1] == count[8]) {
				result = 8;
			} else {
				result = 2;
			}
		} else {
			result = 1;
		}
	} else {
		result = 0;
	}

	printf("%d\n", result);

	return 0;
}
