#include <cstdio>

char S[102];

char result[102];
int resultlen;

int main() {
	scanf("%s", S);

	for (int i = 0; S[i] != 0; i++) {
		char cur = S[i];
		if ('A' <= cur && cur <= 'Z') {
			result[resultlen++] = cur;
		}
	}

	printf("%s\n", result);

	return 0;
}
