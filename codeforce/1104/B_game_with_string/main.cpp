#include <iostream>
#include <cstring>

using namespace std;

char str[100005];
int len;

char stack[100005];
int stacksize;

int main() {
	scanf("%s", str);
	len = strlen(str);

	int count = 0;

	for (int i = 0; i < len; i++) {
		stack[stacksize++] = str[i];

		while (stacksize >= 2) {
			if (stack[stacksize - 1] == stack[stacksize - 2]) {
				stacksize -=2;
				count++;
			} else {
				break;
			}
		}
	}

	printf("%s\n", count % 2 == 1 ? "Yes" : "No");

	return 0;
}
