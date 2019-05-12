#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

bool visited[5003];
stack<int> dfsstack;

int component_ids[5003];

void dfs(int node, vector<int> adj[]) {
	visited[node] = true;

	for (int next : adj[node]) {
		if (!visited[next]) dfs(next, adj);
	}

	dfsstack.push(node);
}

void find_scc(int node, vector<int> inv[], vector<int> &component, int component_id) {
	visited[node] = true;

	for (int next : inv[node]) {
		if (!visited[next]) find_scc(next, inv, component, component_id);
	}

	component.push_back(node);
	component_ids[node] = component_id;
}

int main() {
	while (true) {
		int N, M;
		scanf("%d", &N);
		if (N == 0) break;
		scanf("%d", &M);

		vector<int> adj[5003];
		vector<int> inv[5003];
		vector<vector<int>> components;
		int component_cnt = 0;

		for (int m = 0; m < M; m++) {
			int v, w;
			scanf("%d %d", &v, &w);
			adj[v].push_back(w);
			inv[w].push_back(v);
		}

		memset(visited, 0, sizeof(visited));
		for (int n = 1; n <= N; n++) {
			if (!visited[n]) dfs(n, adj);
		}

		memset(visited, 0, sizeof(visited));
		while (!dfsstack.empty()) {
			int node = dfsstack.top(); dfsstack.pop();
			if (visited[node]) continue;

			components.resize(++component_cnt);
			find_scc(node, inv, components.at(component_cnt - 1), component_cnt);
		}

		vector<int> result;

		for (vector<int> component : components) {
			bool sink = true;
			for (int node : component) {
				for (int next : adj[node]) {
					if (component_ids[node] != component_ids[next]) {
						sink = false;
						break;
					}
				}
			}

			if (sink) {
				for (int node : component) {
					result.push_back(node);
				}
			}
		}

		sort(result.begin(), result.end());
		for (int node : result) {
			printf("%d ", node);
		}
		printf("\n");
	}

	return 0;
}
