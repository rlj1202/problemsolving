#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100005];

bool visited[100005];

int dfn[100005];
int dfncur;
int low[100005];

bool cut[100005];

int dfs(int parent, int v, bool isroot) {
	// There was no problem if I get rid of every codes about
	// comparing parent node. Why?
	
	dfn[v] = ++dfncur;
	low[v] = dfn[v];
	visited[v] = true;

	int childnum = 0;

	for (int next : adj[v]) {
		if (next == parent) continue;
		if (!visited[next]) { // dfs child
			low[v] = min(low[v], dfs(v, next, false));
			childnum++;

			if (!isroot && dfn[v] <= low[next]) // found AP
				cut[v] = true;
		} else {
			low[v] = min(low[v], dfn[next]);
		}
	}

	if (isroot && childnum > 1) // dfs root
		cut[v] = true;

	return low[v];
}

int main() {
	// read input
	int V, E;
	scanf("%d %d", &V, &E);
	while (E--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// find APs
	for (int v = 1; v <= V; v++) { // input graph may not be a connect graph
		if (!visited[v])
			dfs(0, v, true);
	}

	// print results
	int resultnum = 0;
	for (int v = 1; v <= V; v++)
		if (cut[v])
			resultnum++;
	printf("%d\n", resultnum);

	for (int v = 1; v <= V; v++)
		if (cut[v])
			printf("%d ", v);
	printf("\n");

	return 0;
}
