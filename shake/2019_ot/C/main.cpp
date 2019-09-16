#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int nums[100005];
int likelihood[100005];

int sum[100005];
int delta[100005];

int main() {
	// read input
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", nums + n);
	for (int n = 0; n < N; n++) scanf("%d", likelihood + n);

	// binary search
	int l = 0, r = 100000;

	while (r - l > 0) {
		int mid = (l + r) / 2;

		int maxlikelihood = mid;

		// make accum sum of the number of elements which are must be included
		sum[0] = likelihood[0] > maxlikelihood;
		for (int n = 1; n < N; n++)
			sum[n] = sum[n - 1] + (likelihood[n] > maxlikelihood);

		//
		memset(delta, 0, sizeof(delta));

		int isPossible = 1;
		delta[0] = -1;

		for (int n = 0; n < N; n++) {
			if (isPossible) {
				int maxindex = upper_bound(sum, sum + N, sum[n] + nums[n] - 1) - sum;

				delta[n + nums[n] - 1]++;
				delta[maxindex]--;

				if (likelihood[n] <= maxlikelihood) {
					delta[n]++;
					delta[n + 1]--;
				}
			}

			isPossible += delta[n];
		}

		// make decision
		if (isPossible) r = mid;
		else l = mid + 1;
	}
	
	// print result
	printf("%d\n", (l + r) / 2);

	return 0;
}
