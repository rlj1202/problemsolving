#include <iostream>
#include <cstring>
#include <queue>

#define INF 1000000009

using namespace std;

int N, M, K;
vector<pair<int, int>> adj[1003];

priority_queue<pair<int, int>> shortest;
priority_queue<int> path[1003];

void dijkstra(int start) {
	path[1].push(0);
	shortest.push(make_pair(-0, start));

	while (!shortest.empty()) {
		pair<int, int> cur = shortest.top(); shortest.pop();

		for (pair<int, int> edge : adj[cur.second]) {
			int newDistance = -cur.first + edge.first; // cur 까지의 길이와 간선의 길이를 더해 새로운 거리를 구한다.

			if ((int) path[edge.second].size() < K) { // 일단 K개가 짤 때 까지 채운다
				path[edge.second].push(newDistance);
			} else if (path[edge.second].top() > newDistance) { // K개가 모두 찼다면, K 번째 경로를 더 짧게 만들 수 있는지 확인하고 교체한다.
				path[edge.second].pop();
				path[edge.second].push(newDistance);
			} else { // 이미 K 번째 경로가 있으며, 더 이상 짧게 만들 수 없다. 그냥 지나간다.
				continue;
			}

			shortest.push(make_pair(-newDistance, edge.second));
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int m = 1; m <= M; m++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a].push_back(make_pair(c, b));
	}

	dijkstra(1);

	for (int i = 1; i <= N; i++) {
		if ((int) path[i].size() < K) {
			printf("-1\n");
		} else {
			printf("%d\n", path[i].top());
		}
	}

	return 0;
}
