#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

// input
vector<int> adj[100005];

// scc
int visit[100005];
int visit_cur;

int finish[100005];
int finish_cur;

stack<int> s;

// dag
vector<int> dag[100005];

//
bool notroot[100005];

int dfs(int node, vector<vector<int>> &components) {
	visit[node] = ++visit_cur;
	s.push(node);

	int lowest = visit[node];

	for (int next : adj[node]) {
		if (visit[next] == 0)
			lowest = min(lowest, dfs(next, components));
		else if (finish[next] == 0)
			lowest = min(lowest, visit[next]);
	}

	if (visit[node] == lowest) {
		finish_cur++;
		vector<int> comp;

		while (!s.empty()) {
			int cur = s.top(); s.pop();
			finish[cur] = finish_cur;
			comp.push_back(cur);
			if (node == cur) break;
		}

		components.push_back(comp);
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

		for (int n = 0; n < N; n++) adj[n].clear();

		while (M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}

		// find scc
		memset(visit, 0, sizeof(visit));
		memset(finish, 0, sizeof(finish));
		visit_cur = 0;
		finish_cur = 0;
		vector<vector<int>> components;
		for (int n = 0; n < N; n++)
			if (visit[n] == 0) dfs(n, components);

		// find dag
		for (int f = 1; f <= finish_cur; f++) dag[f].clear();
		for (int n = 0; n < N; n++)
			for (int next : adj[n])
				if (finish[n] != finish[next])
					dag[finish[n]].push_back(finish[next]);

		for (int f = 1; f <= finish_cur; f++) {
			sort(dag[f].begin(), dag[f].end());
			dag[f].erase(unique(dag[f].begin(), dag[f].end()), dag[f].end());
		}

		// find roots
		memset(notroot, 0, sizeof(notroot));
		for (int f = finish_cur; f >= 1; f--)
			for (int next : dag[f])
				notroot[next] = true;

		vector<int> result;
		int roots = 0;

		for (int f = 1; f <= finish_cur; f++) {
			if (!notroot[f]) {
				roots++;
				vector<int> comp = components.at(f - 1);
				for (int node : comp) {
					result.push_back(node);
				}
			}
		}

		// print result
		if (roots == 1) {
			sort(result.begin(), result.end());
			for (int node : result) printf("%d\n", node);
		} else {
			printf("Confused\n");
		}
		printf("\n");
	}

	return 0;
}
