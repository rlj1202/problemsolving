#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> adj[300005];
priority_queue<pair<int, int>> shortest;
int out[300005];
int minPath[300005];

int index(int row, int col) {
	return row*(M + 1) + col;
}

int main() {
	scanf("%d %d", &N, &M);
	int start = index(0, 0);
	int dest = index(N, M);

	for (int row = 0; row < N; row++) {
		char str[502];
		scanf("%s", str);

		for (int col = 0; col < M; col++) {
			char c = str[col];

			pair<int, int> a;
			pair<int, int> b;
			int aCost = 0;
			int bCost = 0;

			a.first = index(row+1, col);// '/'
			a.second = index(row, col+1);

			b.first = index(row, col);// '\'
			b.second = index(row+1, col+1);

			if (c == '/') bCost = 1;
			else aCost = 1;

			adj[a.first].push_back(make_pair(aCost, a.second));
			adj[a.second].push_back(make_pair(aCost, a.first));

			adj[b.first].push_back(make_pair(bCost, b.second));
			adj[b.second].push_back(make_pair(bCost, b.first));
		}
	}

	memset(minPath, 63, sizeof(minPath));
	minPath[start] = 0;
	shortest.push(make_pair(-minPath[start], start));

	while (!shortest.empty()) {
		pair<int, int> cur = shortest.top(); shortest.pop();
		if (out[cur.second]) continue;
		out[cur.second] = 1;

		for (pair<int, int> edge : adj[cur.second]) {
			if (!out[edge.second]) {
				int newDistance = minPath[cur.second] + edge.first;

				if (minPath[edge.second] > newDistance) {
					minPath[edge.second] = newDistance;
					shortest.push(make_pair(-newDistance, edge.second));
				}
			}
		}
	}

	int result = minPath[dest];
	if (result == 0x3f3f3f3f) printf("NO SOLUTION");
	else printf("%d", result);

	return 0;
}
