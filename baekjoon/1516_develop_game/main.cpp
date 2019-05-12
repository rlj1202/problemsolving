#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> adj[502];
int costs[502];

int indegrees[502];

priority_queue<int> q;

int results[502];

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		scanf("%d", costs + n);

		int preceding;
		while (true) {
			scanf("%d", &preceding);
			if (preceding == -1) break;

			adj[preceding].push_back(n);
			indegrees[n]++;
		}

		if (indegrees[n] == 0) {
			q.push(n);
			results[n] = costs[n];
		}
	}

	while (!q.empty()) {
		int cur = q.top(); q.pop();

		for (int next : adj[cur]) {
			results[next] = max(results[next], results[cur] + costs[next]);
			if (--indegrees[next] == 0) q.push(next);
		}
	}

	for (int n = 1; n <= N; n++) printf("%d\n", results[n]);

	return 0;
}
