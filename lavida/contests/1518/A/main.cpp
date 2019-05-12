#include <cstdio>

int main() {
	int X;
	scanf("%d", &X);

	int a = X / 10;
	int b = X % 10;

	char grade;
	if (a == 10) {
		grade = 'A';
	} else if (a == 9) {
		grade = 'A';
	} else if (a == 8) {
		grade = 'B';
	} else if (a == 7) {
		grade = 'C';
	} else if (a == 6) {
		grade = 'D';
	} else {
		grade = 'F';
	}

	printf("%c", grade);
	if (a == 10) {
		printf("++");
	} else if (grade != 'F') {
		if (b >= 7) {
			printf("+");
		} else if (b >= 3) {
			printf("");
		} else if (b >= 0) {
			printf("-");
		}
	}
	printf("\n");

	return 0;
}
