#include <cstdio>
#include <cstring>

char S[102];

int main() {
	scanf("%s", S);
	int strl = strlen(S);

	int count = 0;

	int len = 0;
	int prev = S[0] - 1;

	for (int i = 0; i < strl + 1; i++) {
		if (prev + 1 == S[i]) {
			len++;
		} else {
			if (len == 3) count++;

			len = 1;
		}

		prev = S[i];
	}

	printf("%d\n", count);
	
	return 0;
}
