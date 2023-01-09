#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100005];

int tmp[100005];

int main() {
	// read input
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		scanf("%d", arr + n);
	}

	int result = 0x3f3f3f3f;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int cnt = abs(i) + abs(j);

			tmp[1] = arr[1] + i;
			tmp[2] = arr[2] + j;
			int d = tmp[2] - tmp[1];

			bool fail = false;
			for (int n = 3; n <= N; n++) {
				tmp[n] = tmp[n - 1] + d;
				int diff = abs(arr[n] - tmp[n]);

				if (diff > 1) {
					fail = true;
					break;
				} else if (diff == 1) {
					cnt++;
				}
			}

			if (!fail) result = min(result, cnt);
		}
	}

	printf("%d\n", result != 0x3f3f3f3f ? result : -1);

	return 0;
}
