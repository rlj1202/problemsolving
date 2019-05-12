#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[10004];

int main() {
	int V, E;
	scanf("%d %d", &V, &E);
	while (E--) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	return 0;
}
