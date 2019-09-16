#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[5003];

int pi[5003];

int main() {
	scanf("%s", S);

	int result = 0;

	for (int offset = 0; S[offset] != 0; offset++) {
		memset(pi, 0, sizeof(pi));

		int j = 0;
		for (int i = 1; S[offset + i] != 0; i++) {
			while (j && S[offset + i] != S[offset + j])
				j = pi[j - 1];

			if (S[offset + i] == S[offset + j]) {
				pi[i] = ++j;
				result = max(result, j);
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
