#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", arr + n);
	}
	
	bool updated = false;

	for (int n = N - 2; n >= 0; n--) {
		int curmin = arr[n + 1];
		int minidx = n + 1;

		for (int m = n + 1; m < N; m++) {
			if (arr[n] > arr[m]) continue;

			if (curmin > arr[m]) {
				curmin = arr[m];
				minidx = m;
			}
		}

		if (arr[n] < curmin) {
			int tmp = arr[n];
			arr[n] = curmin;
			arr[minidx] = tmp;
			sort(arr + n + 1, arr + N);
			updated = true;
			break;
		}
	}

	if (!updated) {
		printf("-1\n");
		return 0;
	}

	for (int n = 0; n < N; n++)
		printf("%d ", arr[n]);
	printf("\n");

	return 0;
}
