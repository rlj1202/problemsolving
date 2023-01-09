#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[200005];

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d", arr + n);
	}

	sort(arr, arr + N);

	int last = arr[0];
	int len = 1;

	for (int n = 1; n <= N; n++) {
		int cur = arr[n];
		if (last != cur) {
			printf("%d ", len);

			last = cur;
			len = 1;
		} else {
			len++;
		}
	}
	printf("\n");

	printf("%d\n", 0);

	return 0;
}
