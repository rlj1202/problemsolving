#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int seq[1003];

int arr[1003];
int len;

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++)
		scanf("%d", seq + n);

	memset(arr, 63, sizeof(arr));

	for (int n = 1; n <= N; n++) {
		int num = seq[n];
		int i = 0;
		while (num > arr[i]) i++;

		arr[i] = num;
		len = max(len, i + 1);
	}

	printf("%d\n", len);

	return 0;
}
