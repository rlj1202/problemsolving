#include <stdio.h>

int T, N;

int main() {
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		int answer = 0;

		for (int i = 1; i <= N; i++) {
			answer += i;
		}

		printf("%d\n", answer);
	}

	return 0;
}
