#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int parents[100005];
vector<int> adj[100005];

int value[100005];
long long sum[100005];

bool dfs(int node, int depth) {
	if (depth % 2 == 0) {
		if (adj[node].size() == 0) {
			value[node] = 0;
			sum[node] = sum[parents[node]];
		} else {
			int mingap = 0x3f3f3f3f;

			for (int child : adj[node]) {
				int gap = sum[child] - sum[parents[node]];
				if (gap < 0) return false;
				mingap = min(mingap, gap);
			}

			value[node] = mingap;
			sum[node] = sum[parents[node]] + value[node];
		}
	} else {
		value[node] = sum[node] - sum[parents[node]];
	}

	for (int child : adj[node]) {
		if (dfs(child, depth + 1) == false) return false;
	}

	return true;
}

int main() {
	scanf("%d", &N);

	for (int child = 2; child <= N; child++) {
		int parent;
		scanf("%d", &parent);

		parents[child] = parent;
		adj[parent].push_back(child);
	}

	for (int n = 1; n <= N; n++) {
		scanf("%lld", sum + n);
	}

	value[1] = sum[1];

	bool result = dfs(1, 1);
	
	if (result == false) printf("%d\n", -1);
	else {
		long long sum = 0;
		for (int n = 1; n <= N; n++) {
			sum += value[n];
		}
		printf("%lld\n", sum);
	}
	
	return 0;
}
