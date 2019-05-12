#include <iostream>

char str[50];
int stack[50];
int size;

int main() {
	scanf("%s", str);

	size = 0;
	for (int i = 0; str[i] != 0; i++) {
		int c = str[i];
		stack[size++] = c;

		bool updated = true;
		while (updated) {
			updated = false;

			if (size >= 2) {
				if (stack[size - 2] == '(' && stack[size - 1] == ')') {
					size -= 2;
					stack[size++] = -2;
					updated = true;
				} else if (stack[size - 2] == '[' && stack[size - 1] == ']') {
					size -= 2;
					stack[size++] = -3;
					updated = true;
				} else if (stack[size - 2] < 0 && stack[size - 1] < 0) {
					int value = stack[size - 2] + stack[size - 1];
					size -= 2;
					stack[size++] = value;
					updated = true;
				}
			}
			if (size >= 3) {
				if (stack[size - 3] == '(' && stack[size - 1] == ')') {
					int value = stack[size - 2];
					size -= 3;
					stack[size++] = value * 2;
					updated = true;
				} else if (stack[size - 3] == '[' && stack[size - 1] == ']') {
					int value = stack[size - 2];
					size -= 3;
					stack[size++] = value * 3;
					updated = true;
				} 
			}
		}

	}

	if (size == 1 && stack[0] < 0) {
		printf("%d\n", -stack[0]);
	} else {
		printf("0\n");
	}

	return 0;
}
