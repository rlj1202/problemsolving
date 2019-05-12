#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N, M, P;
int speeds[10];
int grid[1003][1003];

int castles[10];

queue<pair<int, int>> queues[10]; // for each player

bool expand(int p, int s) {
	queue<pair<int, int>> q = queues[p];

	bool updated = false;

	while (s--) {
		int curlen = q.size();
		while (curlen--) {
			pair<int, int> cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				pair<int, int> next = {cur.first + dr[i], cur.second + dc[i]};
				if (grid[next.first][next.second] != 0) continue;

				grid[next.first][next.second] = p;
				q.push(next);
				castles[p]++;
				updated = true;
			}
		}
	}

	return updated;
}

int main() {
	scanf("%d %d %d", &N, &M, &P);

	for (int p = 1; p <= P; p++) {
		scanf("%d", speeds + p);
	}

	memset(grid, -1, sizeof(grid));
	for (int r = 1; r <= N; r++) {
		char raw[1003];
		scanf("%s", raw);
		for (int c = 1; c <= M; c++) {
			char cur = raw[c - 1];
			if (cur == '#') {
				grid[r][c] = -1;
			} else if (cur == '.') {
				grid[r][c] = 0;
			} else {
				int p = cur - '0';
				grid[r][c] = p;
				queues[p].push(make_pair(r, c));
				castles[p]++;
			}
		}
	}

	bool updated = true;
	while (updated) {
		updated = false;

		for (int p = 1; p <= P; p++) {
			updated |= expand(p, speeds[p]);
		}
	}

	for (int p = 1; p <= P; p++) printf("%d ", castles[p]);
	printf("\n");

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			printf("%d ", grid[r][c]);
		}
		printf("\n");
	}

	return 0;
}
