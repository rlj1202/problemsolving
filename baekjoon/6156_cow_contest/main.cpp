#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool visited[102];

vector<int> up[102];
vector<int> down[102];

int dfs(vector<int> *adj, int idx) {
	int count = 0;

	for (int next : adj[idx]) {
		if (visited[next]) continue;

		visited[next] = true;

		count++;
		count += dfs(adj, next);
	}

	return count;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++) {
		int a, b;
		scanf("%d %d", &a, &b);
		up[a].push_back(b);
		down[b].push_back(a);
	}

	int result = 0;

	for (int n = 1; n <= N; n++) {
		memset(visited, 0, sizeof(visited));

		visited[n] = true;

		int count = dfs(up, n) + dfs(down, n);
		if (count == N - 1) result++;
	}

	printf("%d\n", result);

	return 0;
}
