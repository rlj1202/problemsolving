#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visited[5003];

int stack[5003];
int stacksize;

int result[5003];
int resultlen;

bool finish[5003];

int component[5003];
int componentsize;
bool outdegree;

void dfs(int node, vector<int> adj[]) {
	visited[node] = true;

	for (int next : adj[node]) {
		if (!visited[next]) dfs(next, adj);
	}

	stack[stacksize++] = node;
}

void inv_dfs(int node, vector<int> adj[], vector<int> inv[]) {
	visited[node] = true;

	for (int next : inv[node]) {
		if (!visited[next]) inv_dfs(next, adj, inv);
	}

	for (int next : adj[node]) {
		if (!visited[next] || finish[next]) outdegree = true;
	}

	component[componentsize++] = node;
}

int main() {
	while (true) {
		memset(visited, 0, sizeof(visited));
		memset(finish, 0, sizeof(finish));
		stacksize = 0;
		resultlen = 0;

		int N;
		scanf("%d", &N);
		if (N == 0) break;

		int M;
		scanf("%d", &M);

		vector<int> adj[5003];
		vector<int> inv[5003];

		for (int m = 0; m < M; m++) {
			int v, w;
			scanf("%d %d", &v, &w);

			adj[v].push_back(w);
			inv[w].push_back(v);
		}

		for (int n = 1; n <= N; n++) {
			if (!visited[n]) dfs(n, adj);
		}

		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < stacksize; i++) {
			int node = stack[stacksize - i - 1];
			if (visited[node]) continue;

			componentsize = 0;
			outdegree = false;

			inv_dfs(node, adj, inv);

			for (int c = 0; c < componentsize; c++) {
				finish[component[c]] = true;
			}

			if (!outdegree) {
				for (int c = 0; c < componentsize; c++) {
					result[resultlen++] = component[c];
				}
			}
		}

		printf("\t\t");
		sort(result, result + resultlen);
		for (int i = 0; i < resultlen; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}

	return 0;
}
