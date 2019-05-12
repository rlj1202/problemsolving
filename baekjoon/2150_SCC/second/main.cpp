#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> adj[10004];

int dfsn[10004];
int dfsncur;

bool finish[10004];

stack<int> s;

vector<vector<int>> components;

int dfs(int node) {
	dfsn[node] = ++dfsncur;
	s.push(node);

	int lowest = dfsn[node];

	for (int next : adj[node]) {
		if (dfsn[next] == 0) // not visited
			lowest = min(lowest, dfs(next));
		else if (!finish[next]) // not finished
			lowest = min(lowest, dfsn[next]);
	}

	// find scc
	if (dfsn[node] == lowest) {
		vector<int> component;

		while (!s.empty()) {
			int cur = s.top(); s.pop();
			component.push_back(cur);
			finish[cur] = true;

			if (cur == node) break;
		}

		sort(component.begin(), component.end());
		components.push_back(component);
	}

	return lowest;
}

int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	for (int e = 0; e < E; e++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}

	for (int v = 1; v <= V; v++) {
		if (dfsn[v] == 0) dfs(v);
	}

	sort(components.begin(), components.end());

	printf("%d\n", (int) components.size());
	for (vector<int> component : components) {
		for (int node : component) {
			printf("%d ", node);
		}
		printf("%d", -1);
		printf("\n");
	}

	return 0;
}
