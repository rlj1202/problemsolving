#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1003];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", arr + n);
	}
	sort(arr, arr + N);

	printf("%d\n", arr[(N - 1) / 2]);

	return 0;
}
