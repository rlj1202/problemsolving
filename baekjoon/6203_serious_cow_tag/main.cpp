#include <iostream>
#include <queue>

using namespace std;

struct Point { int x, y; };

int N;
Point points[1003];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> adj[1003];
bool out[1003];

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x, y;
		scanf("%d %d", &x, &y);
		points[n] = {x, y};
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			int dx = points[i].x - points[j].x;
			int dy = points[i].y - points[j].y;
			int distsquare = dx*dx + dy*dy;

			adj[i].push(make_pair(distsquare, j));
			adj[j].push(make_pair(distsquare, i));
		}
	}

	int cows = N;
	while (cows > 1) {
		for (int i = 0; i < N; i++) {
			if (out[i]) continue;

			while (out[adj[i].top().second]) adj[i].pop();

			pair<int, int> target = adj[i].top();
			out[target.second] = true;
			cows--;
		}
	}

	int winner;
	for (int i = 0; i < N; i++) {
		if (!out[i]) {
			winner = i;
			break;
		}
	}

	printf("%d\n", winner + 1);

	return 0;
}
