#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int seq[1000006];

int arr[1000006];
int len;

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++)
		scanf("%d", seq + n);

	memset(arr, 63, sizeof(arr));

	for (int n = 1; n <= N; n++) {
		int num = seq[n];

		int i = 0;
		while (arr[i] < num) i++;

		arr[i] = num;
		len = max(len, i + 1);
	}

	printf("%d\n", len);

	return 0;
}
