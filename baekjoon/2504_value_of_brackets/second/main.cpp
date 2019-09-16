#include <cstdio>

char str[32];
long long stack[32];
int stacksize;

int main() {
	scanf("%s", str);

	bool invalid = false;

	for (int i = 0; str[i]; i++) {
		char cur = str[i];

		if (cur == '(' || cur == '[') {
			stack[stacksize++] = cur;
		} else if (cur == ')') {
			if (stacksize &&
					stack[stacksize - 1] == '(') {
				stacksize--;
				if (stacksize && stack[stacksize - 1] < 0) {
					stack[stacksize - 1] += -2;
				} else {
					stack[stacksize++] = -2;
				}
			} else if (stacksize >= 2 &&
					stack[stacksize - 1] < 0 &&
					stack[stacksize - 2] == '(') {
				long long value = stack[--stacksize];
				stacksize--;
				value *= 2;
				if (stacksize && stack[stacksize - 1] < 0) {
					stack[stacksize - 1] += value;
				} else {
					stack[stacksize++] = value;
				}
			} else {
				invalid = true;
				break;
			}
		} else if (cur == ']') {
			if (stacksize &&
					stack[stacksize - 1] == '[') {
				stacksize--;
				if (stacksize && stack[stacksize - 1] < 0) {
					stack[stacksize - 1] += -3;
				} else {
					stack[stacksize++] = -3;
				}
			} else if (stacksize >= 2 &&
					stack[stacksize - 1] < 0 &&
					stack[stacksize - 2] == '[') {
				long long value = stack[--stacksize];
				stacksize--;
				value *= 3;
				if (stacksize && stack[stacksize - 1] < 0) {
					stack[stacksize - 1] += value;
				} else {
					stack[stacksize++] = value;
				}
			} else {
				invalid = true;
				break;
			}
		}
	}

	if (!invalid && stacksize == 1)
		printf("%lld\n", -stack[0]);
	else
		printf("0\n");

	return 0;
}
