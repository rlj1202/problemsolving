#include <cstdio>

char str[52];
int stack[52];
int top;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%s", str);
		top = 0;

		bool valid = true;

		for (int i = 0; str[i]; i++) {
			if (str[i] == '(') {
				stack[top++] = str[i];
			} else {
				if (top == 0) {
					valid = false;
					break;
				}

				top--;
			}
		}
		
		if (top) {
			valid = false;
		}

		printf("%s\n", valid ? "YES" : "NO");
	}

	return 0;
}
