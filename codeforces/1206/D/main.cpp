#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

long long nums[100005];
vector<int> adj[100005 + 60];

int main() {
	// read input
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%lld", nums + n);
	}

	// remove same elements
	sort(nums, nums + N);
	N = unique(nums, nums + N) - nums;

	// construct graph
	for (int n = 0; n < N; n++) {
		int tmp = nums[n];
		int i = 0;
		while (tmp) {
			if (tmp & 1) {
				adj[n].push_back(N + i);
				adj[N + i].push_back(n);
			}

			tmp >>= 1;
			i++;
		}
	}

	// find shortest cycle
	for (int i = 0; i < 60; i++) {
		if (adj[N + i].size() >= 3) {
			printf("3\n");
			return 0;
		}
	}



	// print result
	printf("%d\n", 0);

	return 0;
}
