#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int weights[10004];
vector<int> adj[10004];

int dp[10004][2];

int set[10004];
int setsize;

int f(int parent, int n, bool include) {
	if (dp[n][include] != -1) return dp[n][include];

	int result = 0;

	if (include) {
		result += weights[n];

		for (int child : adj[n]) {
			if (child == parent) continue;

			result += f(n, child, false);
		}
	} else {
		for (int child : adj[n]) {
			if (child == parent) continue;

			int exclusive = f(n, child, false);
			int inclusive = f(n, child, true);

			if (inclusive > exclusive) {
				result += inclusive;
			} else {
				result += exclusive;
			}
		}
	}

	return dp[n][include] = result;
}

void findset(int parent, int n, bool include) {
	if (include) {
		for (int child : adj[n]) {
			if (child == parent) continue;

			findset(n, child, false);
		}
	} else {
		for (int child : adj[n]) {
			if (child == parent) continue;

			int exclusive = dp[child][false];
			int inclusive = dp[child][true];

			if (inclusive > exclusive) {
				set[setsize++] = child;
				findset(n, child, true);
			} else {
				findset(n, child, false);
			}
		}
	}

}

int main() {
	// read input
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		scanf("%d", weights + n);
	}
	for (int e = 0; e < N - 1; e++) {
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));

	// set node 1 as root of a tree
	adj[0].push_back(1); // add virture node which is always included
	int result = f(-1, 0, false); // dp!

	// print result
	printf("%d\n", result);

	findset(-1, 0, false);
	sort(set, set + setsize);
	for (int i = 0; i < setsize; i++) printf("%d ", set[i]);
	printf("\n");

	return 0;
}
