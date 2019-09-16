#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int cards[100005];

bool mark[500005];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) scanf("%d", cards + n);

	int p = 1;
	int q = N;

	while (p < q) {
		int k = (p + q + 1) / 2; // binary serach on k, which represents size of each card pack

		int l = 0;
		int r = 0;

		int count = 0;

		while (l < N) {
			if (r < N && !mark[cards[r]] && r - l < k) {
				mark[cards[r++]] = true;
			} else {
				mark[cards[l++]] = false;
			}

			if (r - l == k) {
				count++;
				while (l < r) mark[cards[l++]] = false;
			}
		}

		if (count >= M) { // valid cark pack size
			p = k; // target higher card pack size
		} else {
			q = k - 1; // target lower card pack size
		}
	}

	printf("%d\n", (p + q) / 2);

	return 0;
}
