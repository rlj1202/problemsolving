#include <cstdio>

int getnext(int num) {
	int add = num / 10 + num % 10;
	return (num % 10) * 10 + add % 10;
}

int main() {
	int N;
	scanf("%d", &N);
	int count = 0;
	int cur = N;
	do {
		cur = getnext(cur);
		count++;
	} while (N != cur);
	printf("%d\n", count);
	return 0;
}
