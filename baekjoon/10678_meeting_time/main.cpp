#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> adjA[20];
vector<pair<int, int>> adjB[20];

vector<int> distA;
vector<int> distB;

void f(vector<pair<int, int>> adj[20], vector<int> &dist, int node, int distance) {
	if (node == N) {
		dist.push_back(distance);
		return;
	}

	for (pair<int, int> next : adj[node]) {
		f(adj, dist, next.second, distance + next.first);
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int m = 0; m < M; m++) {
		int s, e, a, b;
		scanf("%d %d %d %d", &s, &e, &a, &b);

		adjA[s].push_back(make_pair(a, e));
		adjB[s].push_back(make_pair(b, e));
	}

	f(adjA, distA, 1, 0);
	f(adjB, distB, 1, 0);

	sort(distA.begin(), distA.end());
	sort(distB.begin(), distB.end());

	int a = 0;
	int b = 0;

	while (a < (int) distA.size() && b < (int) distB.size()) {
		if (distA.at(a) == distB.at(b)) break;
		else if (distA.at(a) < distB.at(b)) a++;
		else b++;
	}

	if (a >= (int) distA.size() || b >= (int) distB.size()) printf("IMPOSSIBLE\n");
	else printf("%d\n", distA.at(a));

	return 0;
}
