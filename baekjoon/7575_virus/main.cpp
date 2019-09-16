#include <cstdio>

int codes[102][1003];

int main() {
	// read input
	int N, K;
	scanf("%d %d", &N, &K);

	for (int n = 0; n < N; n++) {
		int M;
		scanf("%d", &M);

		for (int m = 0; m < M; m++) {
			scanf("%d", codes[n] + m);
		}
	}

	//


	// print result
	printf("%s\n", true ? "YES" : "NO");

	return 0;
}
