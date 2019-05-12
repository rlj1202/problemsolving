#include <iostream>

int N, L;

int main() {
	scanf("%d %d", &N, &L);

	int remains = N;
	int label = 0;
	while (remains) {
		int tmp = ++label;
		bool succeed = true;
		while (tmp) {
			if (tmp % 10 == L) {
				succeed = false;
				break;
			}
			tmp /= 10;
		}
		if (succeed) {
			remains--;
		}
	}

	printf("%d\n", label);

	return 0;
}
