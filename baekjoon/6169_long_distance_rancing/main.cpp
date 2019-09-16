#include <cstdio>

char path[100005];

int main() {
	int M, T, U, F, D;
	scanf("%d %d %d %d %d", &M, &T, &U, &F, &D);
	for (int t = 0; t < T; t++) {
		scanf(" %c", path + t);
	}

	int l = 0, r = T;
	int mid = (l + r) / 2;

	while (l < r) {
		int time = 0;

		for (int t = 0; t < mid; t++) {
			if (path[t] == 'u') {
				time += U;
			} else if (path[t] == 'f') {
				time += F;
			} else if (path[t] == 'd') {
				time += D;
			}
		}
		for (int t = mid - 1; t >= 0; t--) {
			if (path[t] == 'u') {
				time += D;
			} else if (path[t] == 'f') {
				time += F;
			} else if (path[t] == 'd') {
				time += U;
			}
		}

		if (time <= M) {
			l = mid;
		} else {
			r = mid - 1;
		}

		mid = (l + r + 1) / 2;
	}

	printf("%d\n", mid);

	return 0;
}
