#include <iostream>

const char IMPOSSIBLE[] = "I'm Sorry Hansoo";

char str[52];

int count[26];

int odds;
int oddIndex;
int oddCount;

int side[52];
int sidelen;

int mid[52];
int midlen;

int main() {
	// read input
	scanf("%s", str);
	int i = 0;
	while (str[i] != 0) count[str[i++] - 'A']++;

	for (int i = 0; i < 26; i++) {
		if (count[i] % 2 == 1) {
			odds++;
			oddIndex = i;
		}
	}

	if (odds > 1) {
		printf("%s\n", IMPOSSIBLE);
	} else {
		for (int alpha = 0; alpha < 26; alpha++) {
			int cur = count[alpha];

			while (cur >= 2) {
				side[sidelen++] = alpha;
				cur -= 2;
			}

			if (cur) {
				mid[midlen++] = alpha;
			}
		}

		for (int i = 0; i < sidelen; i++) {
			printf("%c", side[i] + 'A');
		}
		for (int i = 0; i < midlen; i++) {
			printf("%c", mid[i] + 'A');
		}
		for (int i = 0; i < sidelen; i++) {
			printf("%c", side[sidelen - i - 1] + 'A');
		}
	}

	return 0;
}
