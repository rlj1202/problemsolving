#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int N, M;
vector<pair<int, int>> adj[1003];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> smallest;
int out[1003];
int cost;

int main() {
	scanf("%d %d", &N, &M);

	for (int m = 1; m <= M; m++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(make_pair(c, b));
		adj[b].push_back(make_pair(c, a));
	}

	out[1] = true;
	for (pair<int, int> edge : adj[1]) {
		smallest.push(edge);
	}

	while (!smallest.empty()) {
		pair<int, int> cur = smallest.top(); smallest.pop();
		if (out[cur.second]) continue;
		out[cur.second] = true;
		cost += cur.first;

		for (pair<int, int> edge : adj[cur.second]) {
			if (!out[edge.second]) smallest.push(edge);
		}
	}

	printf("%d\n", cost);

	return 0;
}
