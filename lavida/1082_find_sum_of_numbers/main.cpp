#include <stdio.h>

int T;
int N, M;

int main() {
	scanf("%d", &T);

	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);

		long long answer = 0;

		for (int i = N; i <= M; i++) {
			answer += i;
		}
		printf("%lld\n", answer);
	}

	return 0;
}
