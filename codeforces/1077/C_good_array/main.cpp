#include <iostream>
#include <algorithm>

using namespace std;

int N;

int height;
int arr[20][200005];

long long sum;

int result[200005];
int len;

void generate() {
	for (int h = 1; h <= height; h++) {
		int prev = 1 << (h - 1);
		int len = 1 << h;

		for (int n = 0; n < N - len + 1; n++) {
			arr[h][n] = max(arr[h - 1][n], arr[h - 1][n + prev]);
		}
	}
}

// l is inclusive
// r is exclusive
int findMax(int l, int r) {
	if (l >= r) return 0;

	int d = r - l;
	int log = 0;
	while ((d >>= 1) != 0) log++;
	int len = 1 << log;

	return max(arr[log][l], arr[log][r - len]);
}

int main() {
	// read input
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%d", arr[0] + n);
		sum += arr[0][n];
	}

	int tmp = N;
	while ((tmp >>= 1) != 0) height++;

	generate();

	//
	for (int n = 0; n < N; n++) {
		int cur = arr[0][n];

		long long changedSum = sum - cur;
		long long changedMax = max(findMax(0, n), findMax(n + 1, N));

		if (changedMax * 2 == changedSum) {
			result[len++] = n;
		}
	}

	// print result
	printf("%d\n", len);
	for (int i = 0; i < len; i++) {
		printf("%d ", result[i] + 1);
	}
	printf("\n");

	return 0;
}
