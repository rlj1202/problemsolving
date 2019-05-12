#include <iostream>

char raw[100005];

int result;

int main() {
	scanf("%s", raw);

	int state = 0;

	for (int i = 0; raw[i] != 0; i++) {
		char cur = raw[i];

		if (state == 0) {
			if (cur == 'H') state++;
		} else if (state == 1) {
			if (cur == 'O') state++;
		} else if (state == 2) {
			if (cur == 'N' ) state++;
		} else if (state == 3) {
			if (cur == 'I') {
				result++;
				state = 0;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
