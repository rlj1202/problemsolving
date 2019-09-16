#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long tree[1 << 18];
long long sumtree[1 << 18];
vector<long long> subsumtree[1 << 18];

int main() {
	// read input
	int N, Q;
	scanf("%d", &N);
	for (int i = 1; i <= (1 << N) - 1; i++) scanf("%lld", tree + i);
	scanf("%d", &Q);

	// make sum tree
	// O(2^N)
	for (int i = 1; i <= (1 << N) - 1; i++) {
		sumtree[i] = tree[i] + sumtree[i / 2];
	}

	// make sub sum tree and sort each of them
	// O(N * 2^N)
	// O(N^2 * 2^N)
	for (int i = 1; i <= (1 << N) - 1; i++) {
		long long num = sumtree[i];
		int node = i;

		while (node) {
			subsumtree[node].push_back(num);
			node /= 2;
		}
	}
	for (int i = 1; i <= (1 << N) - 1; i++) {
		sort(subsumtree[i].begin(), subsumtree[i].end());
	}

	// iterate queries
	// O(Q)
	while (Q--) {
		int A;
		long long D;
		scanf("%d %lld", &A, &D);

		// find planets
		// O(N^2)
		int result = 0;

		long long delta = D - sumtree[A];

		int prevnode = -1;
		int node = A;
		while (node) {
			int left = node * 2;
			int right = node * 2 + 1;

			long long target = delta + sumtree[node] + sumtree[node / 2];

			if (left < (1 << N) && left != prevnode) {
				result +=
					upper_bound(subsumtree[left].begin(), subsumtree[left].end(), target) -
					lower_bound(subsumtree[left].begin(), subsumtree[left].end(), target);
			}

			if (right < (1 << N) && right != prevnode) {
				result +=
					upper_bound(subsumtree[right].begin(), subsumtree[right].end(), target) -
					lower_bound(subsumtree[right].begin(), subsumtree[right].end(), target);
			}

			if (-sumtree[node / 2] == delta) result++;
			
			prevnode = node;
			node /= 2;
		}

		printf("%d\n", result);
	}

	// total time complexity
	// O(N^2 * (Q + 2^N))

	return 0;
}
