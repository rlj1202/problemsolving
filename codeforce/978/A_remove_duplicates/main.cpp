#include <iostream>

int N;
int arr[52];

int flag[1003];

int results[52];
int len;

int main() {
	// read input
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) scanf("%d", arr + n);

	// remove duplicates
	for (int i = 0; i < N; i++) {
		int number = arr[N - i];
		if (flag[number] == 0) {
			flag[number] = 1;
			results[len++] = number;
		}
	}

	// print results
	printf("%d\n", len);
	for (int i = 0; i < len; i++) printf("%d ", results[len - i - 1]);
	printf("\n");

	return 0;
}
