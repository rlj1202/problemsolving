#include <iostream>

int N, M;
int flags[102];

int remains;

int main() {
	// read input
	scanf("%d %d", &N, &M);

	remains = M;
	for (int n = 1; n <= N; n++) {
		int l, r;
		scanf("%d %d", &l, &r);
		while (l <= r) {
			if (flags[l] == 0) {
				flags[l] = 1;
				remains--;
			}
			l++;
		}
	}

	// print result
	printf("%d\n", remains);
	for (int i = 1; i <= M; i++) {
		if (flags[i] == 0) printf("%d ", i);
	}
	printf("\n");

	return 0;
}
