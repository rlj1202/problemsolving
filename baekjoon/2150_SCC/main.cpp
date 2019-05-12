#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> adj[10004];
vector<int> inv[10004];
bool visited[10004];

int stack[10004];
int stacksize;

vector<vector<int>> components;

bool operator< (const vector<int> &a, const vector<int> &b) {
	return a.at(0) < b.at(0);
}

void dfs(int node) {
	visited[node] = true;

	for (int next : adj[node]) {
		if (!visited[next]) dfs(next);
	}

	stack[stacksize++] = node;
}

void inv_dfs(vector<int> &component, int node) {
	visited[node] = true;

	for (int next : inv[node]) {
		if (!visited[next]) inv_dfs(component, next);
	}

	component.push_back(node);
}

int main() {
	// read input
	int V, E;
	scanf("%d %d", &V, &E);
	for (int e = 0; e < E; e++) {
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
		inv[b].push_back(a);
	}

	// do dfs
	for (int v = 1; v <= V; v++) {
		if (!visited[v]) dfs(v);
	}

	// find scc
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < stacksize; i++) {
		int node = stack[stacksize - i - 1]; // backward
		if (visited[node]) continue;

		vector<int> component;
		inv_dfs(component, node);
		sort(component.begin(), component.end());
		components.push_back(component);
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
