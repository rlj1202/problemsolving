#include <iostream>

int len;
char s[52];
char t[52];

int result[10004];
int resultLen;

int main() {
	// read input
	scanf("%d", &len);
	scanf("%s", s);
	scanf("%s", t);

	//
	bool fail = false;

	for (int i = 0; i < len; i++) {
		if (s[i] == t[i]) continue;

		int j = i;
		while (s[j] != t[i] && j < len) j++;

		if (j >= len) {
			fail = true;
			break;
		}

		while (i < j) {
			result[resultLen++] = j;
			int tmp = s[j - 1];
			s[j - 1] = s[j];
			s[j] = tmp;
			j--;
		}
	}

	if (fail) {
		printf("%d\n", -1);
		return 0;
	}

	// print result
	printf("%d\n", resultLen);
	for (int i = 0; i < resultLen; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}
