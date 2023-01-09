#include <iostream>

const char IMPOSSIBLE[] = "Impossible";

char postcard[202];
int K;

char result[202];

bool f(int len, int index) {
	if (postcard[index] == 0) {
		if (len == K) return true;
	} else if (postcard[index + 1] == '*') {
		if (f(len, index + 2)) return true;

		while (len < K) {
			result[len++] = postcard[index];
			if (f(len, index + 2)) return true;
		}
	} else if (postcard[index + 1] == '?') {
		if (f(len, index + 2)) return true;

		result[len] = postcard[index];
		if (f(len++, index + 2)) return true;
	} else {
		result[len++] = postcard[index];
		return f(len, index + 1);
	}

	return false;
}

int main() {
	scanf("%s %d", postcard, &K);

	if (f(0, 0)) {
		result[K] = 0;
		printf("%s\n", result);
	} else printf("%s\n", IMPOSSIBLE);

	return 0;
}
