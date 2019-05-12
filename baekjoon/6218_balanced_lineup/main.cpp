#include <iostream>
#include <algorithm>

using namespace std;

int N, Q;
int min_heights[20][50004];
int max_heights[20][50004];

int main() {
	scanf("%d %d", &N, &Q);
	for (int n = 0; n < N; n++) {
		int height;
		scanf("%d", &height);

		min_heights[0][n] = height;
		max_heights[0][n] = height;
	}

	int tmp = N;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;

	for (int l = 1; l <= log; l++) {
		int len = 1 << l;
		int prevlen = 1 << (l - 1);

		for (int n = 0; n < N - len + 1; n++) {
			min_heights[l][n] = min(min_heights[l - 1][n], min_heights[l - 1][n + prevlen]);
			max_heights[l][n] = max(max_heights[l - 1][n], max_heights[l - 1][n + prevlen]);
		}
	}

	while (Q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;

		int range = b - a + 1;

		int tmp = range;
		int l = 0;
		while ((tmp >>= 1) != 0) l++;
		int len = 1 << l;

		int max_height = max(max_heights[l][a], max_heights[l][b - len + 1]);
		int min_height = min(min_heights[l][a], min_heights[l][b - len + 1]);

		printf("%d\n", max_height - min_height);
	}
	
	return 0;
}
