#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adj[100005];

int visit[100005];
int visit_cur;

int finish[100005];
int finish_cur;

stack<int> s;

bool notroot[100005];

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

		while (!s.empty()) {
			int cur = s.top(); s.pop();
			finish[cur] = finish_cur;
			if (cur == node) break;
		}
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

		for (int n = 1; n <= N; n++) {
			adj[n].clear();
		}

		while (M--) {
			int x, y;
			scanf("%d %d", &x, &y);
			adj[x].push_back(y);
		}

		// find scc
		memset(visit, 0, sizeof(visit));
		memset(finish, 0, sizeof(finish));
		visit_cur = 0;
		finish_cur = 0;

		for (int n = 1; n <= N; n++)
			if (visit[n] == 0) dfs(n);

		// find dag
		memset(notroot, 0, sizeof(notroot));

		for (int n = 1; n <= N; n++)
			for (int next : adj[n])
				if (finish[n] != finish[next])
					notroot[finish[next]] = true;

		int result = 0;
		for (int f = 1; f <= finish_cur; f++) {
			if (!notroot[f]) result++;
		}

		// print result
		printf("%d\n", result);
	}

	return 0;
}
