#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> adj[500005];
int atm[500005];
int restaurants[500005];

int visit[500005];
int visit_cur;

int finish[500005];
int finish_cur;

stack<int> s;

vector<int> dag[500005];
int dag_atm[500005];
int max_atm[500005];

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
		finish_cur++;
		int atm_sum = 0;
		
		while (!s.empty()) {
			int cur = s.top(); s.pop();
			finish[cur] = finish_cur;
			atm_sum += atm[cur];
			if (cur == node) break;
		}

		dag_atm[finish_cur] = atm_sum;
	}

	return lowest;
}

int main() {
	// read input
	int N, M;
	scanf("%d %d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	for (int n = 1; n <= N; n++) {
		scanf("%d", atm + n);
	}
	int S, P;
	scanf("%d %d", &S, &P);
	for (int p = 0; p < P; p++) {
		scanf("%d", restaurants + p);
	}

	// make css
	for (int n = 1; n <= N; n++)
		if (visit[n] == 0) dfs(n);

	// make DAG
	for (int n = 1; n <= N; n++) {
		for (int next : adj[n]) {
			if (finish[n] != finish[next]) dag[finish[n]].push_back(finish[next]);
		}
	}
	for (int f = 1; f <= finish_cur; f++) {
		sort(dag[f].begin(), dag[f].end());
		dag[f].erase(unique(dag[f].begin(), dag[f].end()), dag[f].end());
	}

	// find max atm
	int start_comp = finish[S];
	max_atm[start_comp] = dag_atm[start_comp];
	for (int node = start_comp; node >= 1; node--) {
		for (int next : dag[node]) {
			max_atm[next] = max(max_atm[next], max_atm[node] + dag_atm[next]);
		}
	}

	// print result
	int result = 0;
	for (int p = 0; p < P; p++) {
		int rest = restaurants[p];
		int rest_comp = finish[rest];

		result = max(result, max_atm[rest_comp]);
	}
	printf("%d\n", result);

	return 0;
}
