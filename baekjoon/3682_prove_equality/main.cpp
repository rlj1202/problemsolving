#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int visite[20004];
int visite_id;

int finish[20004];

stack<int> s;

bool notroot[20004];
bool notleaf[20004];

int dfs(int node, vector<int> adj[], vector<vector<int>> &components) {
	visite[node] = ++visite_id;
	s.push(node);
	
	int lowest = visite[node];

	for (int next : adj[node]) {
		if (visite[next] == 0)
			lowest = min(lowest, dfs(next, adj, components));
		else if (finish[next] == 0)
			lowest = min(lowest, visite[next]);
	}

	if (visite[node] == lowest) {
		vector<int> component;

		while (!s.empty()) {
			int cur = s.top(); s.pop();
			component.push_back(cur);
			finish[cur] = components.size() + 1;
			if (node == cur) break;
		}

		components.push_back(component);
	}

	return lowest;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// read input
		int N, M;
		scanf("%d %d", &N, &M);

		vector<int> adj[20004];
		vector<vector<int>> components;

		for (int m = 0; m < M; m++) {
			int s1, s2;
			scanf("%d %d", &s1, &s2);

			adj[s1].push_back(s2);
		}

		// make scc
		memset(visite, 0, sizeof(visite));
		memset(finish, 0, sizeof(finish));
		visite_id = 0;
		for (int n = 1; n <= N; n++) {
			if (visite[n] == 0) dfs(n, adj, components);
		}

		// count leaf scc and root scc
		memset(notroot, 0, sizeof(notroot));
		memset(notleaf, 0, sizeof(notleaf));
		for (int n = 1; n <= N; n++) {
			for (int next : adj[n]) {
				if (finish[n] != finish[next]) {
					notroot[finish[next]] = true;
					notleaf[finish[n]] = true;
				}
			}
		}

		int roots = 0;
		int leaves = 0;
		for (int c = 1; c <= components.size(); c++) {
			if (!notroot[c]) roots++;
			if (!notleaf[c]) leaves++;
		}

		// print result
		if (components.size() > 1) printf("%d\n", max(roots, leaves));
		else printf("%d\n", 0);
	}

	return 0;
}
