#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct State {
	int r, c;
	bool warpzone;

	int distance;

	bool operator> (const State &o) const {
		return distance > o.distance;
	}
};

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int N, T, R, C;
char grid[502][502];

vector<State> adj[502][502][2];

priority_queue<State, vector<State>, greater<State>> pq;
bool out[502][502][2];
int mind[502][502][2];

int main() {
	// read input
	scanf("%d %d %d %d", &N, &T, &R, &C);

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			scanf(" %c", &grid[r][c]);

	// make edges
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			adj[r][c][false].push_back({r, c, true, T});
			adj[r][c][true].push_back({r, c, false, 0});

			for (int i = 0; i < 4; i++) {
				State edge = {r + dr[i], c + dc[i], false, 1};

				if (1 <= edge.r && edge.r <= N &&
						1 <= edge.c && edge.c <= N) {
					adj[r][c][false].push_back(edge);
				}
			}

			if (grid[r][c] != '#') continue;

			for (int i = 0; i < 4; i++) {
				State next = {r + dr[i], c + dc[i]};

				while (1 <= next.r && next.r <= N &&
						1 <= next.c && next.c <= N) {
					adj[next.r][next.c][true].push_back({r, c, true, 1});

					if (grid[next.r][next.c] == '#') break;

					next.r += dr[i];
					next.c += dc[i];
				}
			}
		}
	}

	// do dijkstra
	memset(mind, 0x3f, sizeof(mind));
	mind[1][1][false] = 0;
	pq.push({1, 1, false, 0});

	while (!pq.empty()) {
		State cur = pq.top(); pq.pop();

		if (out[cur.r][cur.c][cur.warpzone]) continue;
		out[cur.r][cur.c][cur.warpzone] = true;

		for (State edge : adj[cur.r][cur.c][cur.warpzone]) {
			State next = edge;
			next.distance += cur.distance;

			if (mind[next.r][next.c][next.warpzone] > next.distance) {
				mind[next.r][next.c][next.warpzone] = next.distance;

				pq.push(next);
			}
		}
	}

	// print result
	printf("%d\n", min(mind[R][C][false], mind[R][C][true]));

	return 0;
}
