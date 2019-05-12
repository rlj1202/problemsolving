#include <cstdio>

int T;

int main() {
	scanf("%d", &T);

	while (T--) {
		int numbers[7];
		for (int i = 0; i < 7; i++) {
			scanf("%d", numbers + i);
		}

		int matches = 0;
		bool bonus = false;

		for (int i = 0; i < 6; i++) {
			int num;
			scanf("%d", &num);

			for (int j = 0; j < 7; j++) {
				if (num == numbers[j]) {
					matches++;
					if (j == 6) bonus = true;
					break;
				}
			}
		}

		int prize = 0;

		if (matches == 6) {
			if (!bonus) {
				prize = 1;
			} else {
				prize = 2;
			}
		} else if (matches == 5) {
			prize = 3;
		} else if (matches == 4) {
			prize = 4;
		} else if (matches == 3) {
			prize = 5;
		}

		if (prize) {
			printf("%d\n", prize);
		} else {
			printf("Fail\n");
		}
	}

	return 0;
}
