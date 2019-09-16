#include <cstdio>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	if (M == 1) {
		int K;
		scanf("%d", &K);
	} else { // M == 2
		for (int n = 0; n < N; n++) {
			scanf("%d");
		}
	}

	return 0;
}
