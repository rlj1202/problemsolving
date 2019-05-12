#include <iostream>

int N;
int arr[1003];

int main() {
	// read input
	scanf("%d", &N);
	
	for (int n = 0; n < N; n++) scanf("%d", arr + n);

	//
	for (int n = 0; n < N; n++) {
		if (arr[n] % 2 == 0) arr[n]--;
	}

	// print result
	for (int n = 0; n < N; n++) printf("%d ", arr[n]);
	printf("\n");

	return 0;
}
