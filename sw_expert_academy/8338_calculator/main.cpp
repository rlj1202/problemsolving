#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);

		int result = 0;

		for (int n = 0; n < N; n++) {
			int num;
			scanf("%d", &num);

			if (result + num > result * num) {
				result += num;
			} else {
				result *= num;
			}
		}

		printf("#%d %d\n", t, result);
	}

	return 0;
}
