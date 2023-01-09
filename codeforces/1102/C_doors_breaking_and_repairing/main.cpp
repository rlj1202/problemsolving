#include <iostream>

int N, X, Y;
int doors[102];

int main() {
	scanf("%d %d %d", &N, &X, &Y);

	int cnt = 0;

	for (int n = 0; n < N; n++) {
		scanf("%d", doors + n);
		if (doors[n] <= X) {
			cnt++;
		}
	}

	if (X > Y) {
		printf("%d\n", N);
	} else {
		printf("%d\n", (cnt + 1) / 2);
	}

	return 0;
}
