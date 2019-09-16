#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[202];

int cows[202];
int barns[202];

bool visited[202];

bool findmatch(int cow) {
	visited[cow] = true;

	for (int barn : adj[cow]) {
		if (barns[barn] == -1 || (!visited[barns[barn]] && findmatch(barns[barn]))) {
			cows[cow] = barn;
			barns[barn] = cow;
			return true;
		}
	}

	return false;
}

int main() {
	// read input
	int N, M;
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) {
		int S;
		scanf("%d", &S);

		for (int s = 0; s < S; s++) {
			int barn;
			scanf("%d", &barn);
			adj[n].push_back(barn);
		}
	}

	// bipartite matching
	int matchs = 0;

	memset(cows, -1, sizeof(cows));
	memset(barns, -1, sizeof(barns));
	for (int n = 0; n < N; n++) {
		if (cows[n] == -1) {
			memset(visited, false, sizeof(visited));
			if (findmatch(n)) matchs++;
		}
	}

	// print result
	printf("%d\n", matchs);

	return 0;
}
