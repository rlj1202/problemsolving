#include <iostream>

int N;
char raw[300005];

int counts[3];

int main() {
	scanf("%d %s", &N, raw);

	for (int n = 0; n < N; n++) counts[raw[n] - '0']++;
	for (int i = 0; i < 3; i++) counts[i] -= N / 3;

	int l = 0;
	int r = N - 1;

	while (l < N && r >= 0) {
		if (l < N) {
			int left = raw[l] - '0';
			if (counts[left] > 0) {
				int to = left;
				for (int i = 0; i < 3; i++) {
					if (counts[i] < 0) {
						to = i;
						break;
					}
				}

				if (left > to) {
					raw[l] = to + '0';
					counts[left]--;
					counts[to]++;
				}
			}
			l++;
		}

		if (r >= 0) {
			int right = raw[r] - '0';
			if (counts[right] > 0) {
				int to = right;
				for (int i = 2; i >= 0; i--) {
					if (counts[i] < 0) {
						to = i;
						break;
					}
				}

				if (right < to) {
					raw[r] = to + '0';
					counts[right]--;
					counts[to]++;
				}
			}
			r--;
		}
	}

	printf("%s\n", raw);

	return 0;
}
