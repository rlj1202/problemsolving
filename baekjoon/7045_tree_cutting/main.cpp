#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> adj[10004];

int parents[10004];
int counts[10004];

int dfs(int parent, int node) {
	int sum = 0;
	parents[node] = parent;
	for (int child : adj[node]) {
		if (child == parent) continue;
		sum += dfs(node, child);
	}
	return counts[node] = sum + 1;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N - 1; n++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(0, 1);

	int half = N / 2;

	for (int n = 1; n <= N; n++) {
		if (N - counts[n] > half) continue;
		bool valid = true;
		for (int next : adj[n]) {
			if (next == parents[n]) continue;
			if (counts[next] > half) {
				valid = false;
				break;
			}
		}
		if (!valid) continue;

		printf("%d\n", n);
	}

	return 0;
}
