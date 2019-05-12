#include <stdio.h>

int N;

int main() {
	scanf("%d", &N);

	int a = 0;
	int b = 1;

	while (N--) {
		int c = a + b;
		a = b;
		b = c;
	}

	printf("%d\n", a);

	return 0;
}
