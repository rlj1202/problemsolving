#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[10004];

int visit[10004];
int visit_cur;

int finish[10004];
int finish_cur;

stack<int> s;

vector<int> dag[10004];
int dagnodesize[10004];
int dagnodecnt;

int max_cities[10004];

int dfs(int node) {
	visit[node] = ++visit_cur;
	s.push(node);

	int lowest = visit[node];

	for (int next : adj[node]) {
		if (visit[next] == 0)
			lowest = min(lowest, dfs(next));
		else if (finish[next] == 0)
			lowest = min(lowest, visit[next]);
	}

	if (visit[node] == lowest) {
		int count = 0;
		finish_cur++;

		while (!s.empty()) {
			int cur = s.top(); s.pop();
			finish[cur] = finish_cur;
			count++;
			if (node == cur) break;
		}

		dagnodesize[finish_cur] = count;
		dagnodecnt++;
	}

	return lowest;
}

int main() {
	// read input
	int N, M, S, T;
	scanf("%d %d %d %d", &N, &M, &S, &T);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}

	// make scc
	for (int n = 1; n <= N; n++)
		if (visit[n] == 0)
			dfs(n);

	// construct DAG(Directed Acyclic Graph)
	for (int n = 1; n <= N; n++)
		for (int next : adj[n])
			if (finish[n] != finish[next])
				dag[finish[n]].push_back(finish[next]);

	for (int f = 1; f <= finish_cur; f++) {
		sort(dag[f].begin(), dag[f].end());
		dag[f].erase(
				unique(dag[f].begin(), dag[f].end()),
				dag[f].end());
	}

	// count max cities we can travle
	int s = finish[S];
	int t = finish[T];

	max_cities[s] = dagnodesize[s];
	for (int node = s; node >= 1; node--) {
		for (int next : dag[node]) {
			max_cities[next] = max(max_cities[next], max_cities[node] + dagnodesize[next]);
		}
	}

	// print result
	printf("%d\n", max_cities[t]);

	// XXX
	for (int c = 1; c <= dagnodecnt; c++) {
		printf("\t%d : ", c);
		for (int next : dag[c]) printf("%d ", next);
		printf("\n");
	}
	printf("\n\t");
	for (int c = 1; c <= dagnodecnt; c++) printf("%d ", max_cities[c]);
	printf("\n");

	return 0;
}
