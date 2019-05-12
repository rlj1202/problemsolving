#include <iostream>

int N;
char raw[102];

int result;

int main() {
	// read input
	scanf("%d", &N);
	scanf("%s", raw);

	// handle substring 'xxx'
	int len = 0;
	for (int i = 0; i <= N; i++) {
		char c = raw[i];
		if (c == 'x') {
			len++;
		} else {
			if (len >= 3) result += len - 2;
			len = 0;
		}
	}

	// print result
	printf("%d\n", result);

	return 0;
}
