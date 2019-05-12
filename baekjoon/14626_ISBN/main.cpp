#include <iostream>

const int weights[] = {1, 3};
char isbn[14];
int ruined;
int sum;

int main() {
	scanf("%s", isbn);
	for (int i = 0; i < 13; i++) {
		if (isbn[i] == '*') {
			ruined = i;
			continue;
		}
		sum += weights[i % 2] * (isbn[i] - '0');
	}

	for (int d = 0; d <= 9; d++) {
		if ((sum + d * weights[ruined % 2]) % 10 == 0) {
			printf("%d\n", d);
			break;
		}
	}

	return 0;
}
