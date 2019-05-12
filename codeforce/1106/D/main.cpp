#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[100005];

priority_queue<int, vector<int>, greater<int>> q;
int visited[100005];

int result[100005];
int resultlen;

int main() {
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	q.push(1);
	
	while (!q.empty()) {
		int cur = q.top(); q.pop();
		if (visited[cur]) continue;

		visited[cur] = 1;
		result[resultlen++] = cur;

		for (int next : adj[cur]) {
			if (!visited[next]) q.push(next);
		}
	}

	for (int n = 0; n < N; n++) printf("%d ", result[n]);
	printf("\n");

	return 0;
}
