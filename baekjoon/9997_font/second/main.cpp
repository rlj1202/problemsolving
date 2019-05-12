#include <iostream>

int N;
int words[25];

const int MASK = (1 << 26) - 1;

int f(int n, int curMask) {
	if (n >= N) return curMask == MASK;
	return f(n + 1, curMask | words[n]) + f(n + 1, curMask);
}

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		char word[101];
		scanf("%s", word);

		for (int i = 0; word[i] != 0; i++) words[n] |= 1 << (word[i] - 'a');
	}

	printf("%d\n", f(0, 0));

	return 0;
}
