#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

// input
int N;
int adj[302][302];

// scc
int visit[302];
int visit_cur;

int finish[302];
int finish_cur;

stack<int> s;

// dag
int dag[302][302];

int dfs(int node, vector<int> components[]) {
	visit[node] = ++visit_cur;
	s.push(node);

	int lowest = visit[node];

	for (int next = 1; next <= N; next++) {
		if (adj[node][next] == 0) continue;

		if (visit[next] == 0)
			lowest = min(lowest, dfs(next, components));
		else if (finish[next] == 0)
			lowest = min(lowest, visit[next]);
	}

	if (visit[node] == lowest) {
		finish_cur++;

		while (!s.empty()) {
			int cur = s.top(); s.pop();
			finish[cur] = finish_cur;
			components[finish_cur].push_back(cur);
			if (node == cur) break;
		}
	}

	return lowest;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// read input
		scanf("%d", &N);
		for (int n = 1; n <= N; n++) {
			for (int m = 1; m <= N; m++) {
				scanf("%1d", &adj[n][m]);
			}
		}

		// make scc
		memset(visit, 0, sizeof(visit));
		memset(finish, 0, sizeof(finish));
		visit_cur = 0;
		finish_cur = 0;
		vector<int> components[302];

		for (int n = 1; n <= N; n++)
			if (visit[n] == 0) dfs(n, components);

		// make dag
		memset(dag, 0, sizeof(dag));
		for (int n = 1; n <= N; n++) {
			for (int next = 1; next <= N; next++) {
				if (adj[n][next] == 0) continue;
				if (finish[n] != finish[next])
					dag[finish[n]][finish[next]] = 1;
			}
		}

		// construct roads
		vector<int> roads[302];
		int road_cnt = 0;

		for (int k = 1; k <= finish_cur; k++)
			for (int i = 1; i <= finish_cur; i++)
				for (int j = 1; j <= finish_cur; j++)
					if (dag[i][k] && dag[k][j]) dag[i][j] = 0;

		for (int f = 1; f <= finish_cur; f++) {
			if (components[f].size() > 1) {
				int prev = components[f].back();
				for (int node : components[f]) {
					roads[prev].push_back(node);
					road_cnt++;
					prev = node;
				}
			}

			for (int next = 1; next <= finish_cur; next++) {
				if (dag[f][next] == 0) continue;

				roads[components[f].front()].push_back(components[next].front());
				road_cnt++;
			}
		}

		// print result
		printf("%d\n", road_cnt);
		for (int n = 1; n <= N; n++) {
			for (int next : roads[n]) {
				printf("%d %d\n", n, next);
			}
		}
		printf("\n");

		// XXX
		for (int f = 1; f <= finish_cur; f++) {
			printf("\tscc %d : { ", f);
			for (int node : components[f]) {
				printf("%d ", node);
			}
			printf("}\n");
		}
		printf("\n");
		for (int f = 1; f <= finish_cur; f++) {
			printf("\tdag %d : ", f);
			for (int next = 1; next <= finish_cur; next++) {
				if (dag[f][next] == 0) continue;
				printf("%d ", next);
			}
			printf("\n");
		}
	}

	return 0;
}
