#include <cstdio>

int N;
char S[1000006];

int pi[1000006];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
		scanf(" %c", S + n);
	for (int n = 0; n < N; n++)
		scanf(" %*c");

	int j = 0;
	for (int i = 1; S[i] != 0; i++) {
		while (j && S[i] != S[j])
			j = pi[j - 1];
		if (S[i] == S[j]) {
			pi[i] = ++j;
		}
	}

	printf("1/%d\n", N - j);

	return 0;
}
