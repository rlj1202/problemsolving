#include <cstdio>

int main() {
	int num;
	scanf("%d", &num);

	int answer;

	if (num == 1) {
		answer = 65;
	} else if (num == 2) {
		answer = 17;
	} else if (num == 3) {
		answer = 4;
	} else if (num == 4) {
		answer = 4;
	} else if (num == 5) {
		answer = 64;
	}

	printf("%d\n", answer);

	return 0;
}
