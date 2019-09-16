#include <cstdio>
#include <cstring>

char oct[333334 + 1];

char bin[1000006];
int top;

int main() {
	scanf("%s", oct);

	int len = strlen(oct);
	for (int i = len - 1; i >= 0; i--) {
		int value = oct[i] - '0';
		for (int j = 0; j < 3; j++) {
			bin[top++] = ((value >> j) & 1) + '0';
		}
	}

	while (top > 1 && bin[top - 1] == '0') {
		top--;
	}
	while (top) {
		printf("%c", bin[--top]);
	}
	printf("\n");

	return 0;
}
