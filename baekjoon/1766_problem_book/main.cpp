#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[32004];

int indegrees[32004];

priority_queue<int, vector<int>, greater<int>> q;

int main() {
	scanf("%d %d", &N, &M);

	for (int m = 1; m <= M; m++) {
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
		indegrees[b]++;
	}

	for (int n = 1; n <= N; n++) {
		if (indegrees[n] == 0) q.push(n);
	}

	while (!q.empty()) {
		int cur = q.top(); q.pop();
		printf("%d ", cur);

		for (int next : adj[cur]) {
			if (--indegrees[next] == 0) q.push(next);
		}
	}
	printf("\n");

	return 0;
}
