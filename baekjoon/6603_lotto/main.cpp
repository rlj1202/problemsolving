#include <iostream>

int K;
int set[20];

int curset[20];

void func(int numidx, int count) {
	if (count == 6) {
		for (int i = 0; i < 6; i++) printf("%d ", curset[i]);
		printf("\n");
	}

	for (int i = numidx; i < K; i++) {
		curset[count] = set[i];

		func(i + 1, count + 1);
	}
}

int main() {
	while (true) {
		scanf("%d", &K);
		if (K == 0) break;

		for (int k = 0; k < K; k++) scanf("%d", set + k);

		func(0, 0);
		printf("\n");
	}

	return 0;
}
