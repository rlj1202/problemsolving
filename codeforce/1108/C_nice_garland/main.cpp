#include <iostream>

int N;
char str[200005];

int cnt[3][3];

int main() {
	scanf("%d", &N);
	scanf("%s", str);

	for (int n = 0; n < N; n++) {
		int col = n % 3;
		int lamp;

		char c = str[n];
		if (c == 'R') lamp = 0;
		else if (c == 'G') lamp = 1;
		else lamp = 2;

		cnt[col][lamp]++;
	}

	int min = 0x3f3f3f3f;
	int pattern[3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
			for (int k = 0; k < 3; k++) {
				if (i == k || j == k) continue;

				int cost = 0;
				cost += cnt[0][j] + cnt[0][k];
				cost += cnt[1][i] + cnt[1][k];
				cost += cnt[2][i] + cnt[2][j];

				if (min > cost) {
					min = cost;
					pattern[0] = i;
					pattern[1] = j;
					pattern[2] = k;
				}
			}
		}
	}

	printf("%d\n", min);
	for (int n = 0; n < N; n++) {
		printf("%c", "RGB"[pattern[n % 3]]);
	}
	printf("\n");

	return 0;
}
