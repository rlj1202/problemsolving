#include <iostream>

const char IMPOSSIBLE[] = "Impossible";

char postcard[202];
int K;

int minlen;

char result[202];

bool fill(int len, int index, int required) {
	if (postcard[index] == 0) {
		return len == K;
	} else if (postcard[index + 1] == '?') {
		if (required > 0) {
			required--;
			result[len++] = postcard[index];
		}
		
		return fill(len, index + 2, required);
	} else if (postcard[index + 1] == '*') {
		while (required > 0) {
			required--;
			result[len++] = postcard[index];
		}
		
		return fill(len, index + 2, required);
	} else {
		result[len++] = postcard[index];
		return fill(len, index + 1, required);
	}

	return false;
}

int main() {
	scanf("%s %d", postcard, &K);

	int i = 0;
	while (postcard[i] != 0) {
		if (postcard[i + 1] == '*') {
			i += 2;
		} else if (postcard[i + 1] == '?') {
			i += 2;
		} else {
			i++;
			minlen++;
		}
	}

	if (minlen > K) {
		printf("%s\n", IMPOSSIBLE);
	} else {
		int required = K - minlen;

		bool possible = fill(0, 0, required);

		if (possible) printf("%s\n", result);
		else printf("%s\n", IMPOSSIBLE);
	}

	return 0;
}
