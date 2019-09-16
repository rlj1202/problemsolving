#include <cstdio>

char hex[7];

int main() {
	scanf("%s", hex);

	int result = 0;

	for (int i = 0; hex[i]; i++) {
		result *= 16;
		if ('0' <= hex[i] && hex[i] <= '9') result += hex[i] - '0';
		if ('A' <= hex[i] && hex[i] <= 'F') result += hex[i] - 'A' + 10;
	}

	printf("%d\n", result);

	return 0;
}
