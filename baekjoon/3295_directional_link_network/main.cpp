#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[1003];

int toward[1003];
int back[1003];
bool visited[1003];

bool find_match(int u) {
	visited[u] = true;

	for (int next : adj[u]) {
		if (back[next] == -1 || (!visited[back[next]] && find_match(back[next]))) {
			toward[u] = next;
			back[next] = u;
			return true;
		}
	}

	return false;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);

		for (int m = 0; m < M; m++) {
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}

		memset(toward, -1, sizeof(toward));
		memset(back, -1, sizeof(back));

		int result = 0;
		
		bool updated = true;
		while (updated) {
			updated = false;

			for (int n = 0; n < N; n++) {
				if (toward[n] != -1) continue;

				memset(visited, false, sizeof(visited));
				if (find_match(n)) {
					result++;
					updated = true;
				}
			}
		}
		for (int n = 0; n < N; n++) adj[n].clear();

		printf("%d\n", result);
	}

	return 0;
}
