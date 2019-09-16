#include <cstdio>

char rod[100005];
char stack[100005];
int pos[100005];
int stacksize;

int result;

int main() {
	scanf("%s", rod);
	for (int i = 0; rod[i]; i++) {
		char cur = rod[i];

		if (cur == '(') {
			stack[stacksize] = cur;
			pos[stacksize] = i;
			stacksize++;
		} else { // cur == ')'
			stacksize--;
			if (i - pos[stacksize] == 1) {
				result += stacksize;
			} else {
				result += 1;
			}
		}
	}

	printf("%d\n", result);
	
	return 0;
}
