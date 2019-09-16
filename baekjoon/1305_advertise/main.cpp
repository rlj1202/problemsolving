#include <cstdio>

int L;
char S[1000006];

int pi[1000006];

int main() {
	scanf("%d %s", &L, S);

	int j = 0;
	for (int i = 1; S[i] != 0; i++) {
		while (j && S[i] != S[j])
			j = pi[j - 1];

		if (S[i] == S[j]) {
			pi[i] = ++j;
		}
	}

	printf("%d\n", L - j);

	return 0;
}
