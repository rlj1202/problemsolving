#include <iostream>

int K;
char signs[9];
int seq[9];

int main() {
	scanf("%d", &K);
	for (int k = 0; k < K; k++) {
		scanf(" %c", signs + k);
	}

	int digit;

	digit = 9;
	for (int i = 0; i < K + 1; i++) {
		seq[i] = digit--;

		for (int j = i - 1; j >= 0; j--) {
			char sign = signs[j];

			if (sign == '<') {
				if (seq[j] > seq[j + 1]) {
					int tmp = seq[j];
					seq[j] = seq[j + 1];
					seq[j + 1] = tmp;
				}
			} else if (sign == '>') {
				if (seq[j] < seq[j + 1]) {
					int tmp = seq[j];
					seq[j] = seq[j + 1];
					seq[j + 1] = tmp;
				}
			}
		}
	}

	for (int i = 0; i < K + 1; i++) printf("%d", seq[i]);
	printf("\n");

	digit = 0;
	for (int i = 0; i < K + 1; i++) {
		seq[i] = digit++;

		for (int j = i - 1; j >= 0; j--) {
			char sign = signs[j];

			if (sign == '<') {
				if (seq[j] > seq[j + 1]) {
					int tmp = seq[j];
					seq[j] = seq[j + 1];
					seq[j + 1] = tmp;
				}
			} else if (sign == '>') {
				if (seq[j] < seq[j + 1]) {
					int tmp = seq[j];
					seq[j] = seq[j + 1];
					seq[j + 1] = tmp;
				}
			}
		}
	}

	for (int i = 0; i < K + 1; i++) printf("%d", seq[i]);
	printf("\n");

	return 0;
}
