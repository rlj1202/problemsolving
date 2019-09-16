#include <cstdio>

int ratings[1003];

int main() {
	int N, T;
	scanf("%d %d", &N, &T);
	for (int n = 0; n < N; n++) {
		scanf("%d", ratings + n);
	}

	for (int t = 0; t < T; t++) {
		int song = 0;
		int curmax = ratings[0];

		for (int n = 0; n < N; n++) {
			if (curmax < ratings[n]) {
				curmax = ratings[n];
				song = n;
			}
		}

		int dist = curmax / (N - 1);

		for (int n = 0; n < N; n++) {
			if (n == song) continue;
			ratings[n] += dist;
			curmax -= dist;
		}
		for (int n = 0; n < N && curmax; n++) {
			if (n == song) continue;
			ratings[n]++;
			curmax--;
		}

		ratings[song] = 0;

		printf("%d\n", song + 1);
	}

	return 0;
}
