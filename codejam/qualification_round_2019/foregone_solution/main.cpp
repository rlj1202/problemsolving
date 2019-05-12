#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);

		int a[102];
		int alen = 0;
		int b[102];
		int blen = 0;

		for (int tmp = N; tmp; tmp /= 10) {
			a[alen++] = tmp % 10;
		}

		for (int i = 0; i < alen; i++) {
			if (a[i] == 4) {
				a[i] = 3;
				b[i] = 1;

				blen = i + 1;
			} else {
				b[i] = 0;
			}
		}

		printf("Case #%d: ", t);
		for (int i = 0; i < alen; i++) {
			printf("%d", a[alen - i - 1]);
		}
		printf(" ");
		for (int i = 0; i < blen; i++) {
			printf("%d", b[blen - i - 1]);
		}
		printf("\n");
	}
}
