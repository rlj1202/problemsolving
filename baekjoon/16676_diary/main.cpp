#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);

	int result = 1;
	
	for (int threshold = 11; threshold <= N; threshold = threshold * 10 + 1) {
		result++;
	}

	printf("%d\n", result);

	return 0;
}
