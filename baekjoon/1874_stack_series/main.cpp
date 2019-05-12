#include <iostream>

int N;
int series[100005];

int stack[100005];
int size;

int pointer;

char result[200005];
int len;

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", series + n);

	for (int n = 1; n <= N; n++) {
		while (size > 0 && stack[size - 1] == series[pointer]) {
			size--;
			pointer++;

			result[len++] = '-';
		}

		stack[size++] = n;

		result[len++] = '+';
	}

	while (size > 0 && stack[size - 1] == series[pointer]) {
		size--;
		pointer++;
		
		result[len++] = '-';
	}

	if (pointer == N) {
		for (int i = 0; i < len; i++) printf("%c\n", result[i]);
	} else {
		printf("NO\n");
	}

	return 0;
}
