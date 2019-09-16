#include <cstdio>
#include <cstring>

char S[1000006];

int pi[1000006];

int main() {
	while (true) {
		scanf("%s", S);
		if (S[0] == '.') break;

		memset(pi, 0, sizeof(pi));

		int i;
		int j = 0;
		for (i = 1; S[i] != 0; i++) {
			while (j && S[i] != S[j])
				j = pi[j - 1];

			if (S[i] == S[j]) {
				pi[i] = ++j;
			}
		}

		int wordlen = i - j;

		if (i % wordlen != 0) wordlen = i;

		printf("%d\n", i / wordlen);
	}

	return 0;
}
