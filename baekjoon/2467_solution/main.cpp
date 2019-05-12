#include <iostream>
#include <algorithm>

using namespace std;

int N;
int sols[100005];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", sols + n);

	int l = 0;
	int r = N - 1;

	int minsum = sols[l] + sols[r];
	int a = l;
	int b = r;

	while (l < r) {
		if (abs(minsum) > abs(sols[l] + sols[r])) {
			minsum = sols[l] + sols[r];
			a = l;
			b = r;
		}

		if (abs(sols[l]) > abs(sols[r])) {
			l++;
		} else {
			r--;
		}
	}

	printf("%d %d\n", sols[a], sols[b]);

	return 0;
}
