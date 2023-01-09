#include <cstdio>

bool chk[52];
int count;

int main() {
	int N, V;
	scanf("%d %d", &N, &V);
	for (int n = 0; n < N; n++) {
		int K;
		scanf("%d", &K);
		
		bool possible = false;

		for (int k = 0; k < K; k++) {
			int price;
			scanf("%d", &price);

			if (V > price) possible = true;
		}

		chk[n] = possible;
		if (possible) count++;
	}

	printf("%d\n", count);
	for (int n = 0; n < N; n++) {
		if (chk[n]) printf("%d ", n + 1);
	}
	printf("\n");

	return 0;
}
