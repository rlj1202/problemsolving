#include <iostream>

int N, M;
long long map[52];

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			long long value;
			scanf("%lld", &value);
			map[n] += value;
		}
	}

	long long flag = 0;
	for (int n = 1; n <= N; n++) flag ^= map[n];

	if (flag == 0) printf("ainta");
	else printf("august14");

	return 0;
}
