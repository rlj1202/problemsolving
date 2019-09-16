#include <cstdio>
#include <vector>

using namespace std;

int N, M, Q;

vector<int> adj[1003];

int indegree[1003];

int main() {
	scanf("%d %d %d", &N, &M, &Q);

	for (int m = 0; m < M; m++) {
		int a, b;
		scanf("%d %d", &a, &b);

		adj[b].push_back(a);
		indegree[a]++;
	}

	while (Q--) {
		int w, x, y;
		scanf("%d %d %d", &w, &x, &y);

		if (w == 1) {
			for (int i = x; i <= y; i++) {
				for (int next : adj[i]) {
					indegree[next]--;
				}
			}
			
			bool possible = true;

			for (int i = x; i <= y; i++) {
				if (indegree[i] != 0) possible = false;
			}

			for (int i = x; i <= y; i++) {
				for (int next : adj[i]) {
					indegree[next]++;
				}
			}

			if (possible) printf("YES\n");
			else printf("NO\n");
		} else if (w == 2) {
		} else { // w == 3
		}
	}

	return 0;
}
