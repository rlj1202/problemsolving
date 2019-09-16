#include <cstdio>

int cows[20004];

int main() {
	int N, S;
	scanf("%d %d", &N, &S);
	for (int n = 0; n < N; n++) scanf("%d", cows + n);

	int result = 0;

	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
			if (cows[i] + cows[j] <= S) result++;

	printf("%d\n", result);

	return 0;
}
