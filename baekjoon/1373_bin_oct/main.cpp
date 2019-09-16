#include <cstdio>
#include <cstring>

char bin[1000006];

char oct[400005];
int top;

int main() {
	scanf("%s", bin);
	
	int len = strlen(bin);
	while (len) {
		int value = 0;
		for (int i = 0; i < 3 && len; i++) {
			value += (bin[--len] - '0') << i;
		}
		oct[top++] = value + '0';
	}
	
	while (top) {
		printf("%c", oct[--top]);
	}
	printf("\n");

	return 0;
}
