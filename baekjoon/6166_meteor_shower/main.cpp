#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Point { int x, y, t; };

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

Point meteors[50004];
int front;

bool unsafe[402][402];
bool destroyed[402][402];

int visited[402][402];
queue<Point> q;

int main() {
	int M;
	scanf("%d", &M);
	for (int m = 0; m < M; m++) {
		int x, y, t;
		scanf("%d %d %d", &x, &y, &t);
		meteors[m] = {x, y, t};

		unsafe[x][y] = true;
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] < 0 || y + dy[i] < 0 ||
					x + dx[i] > 400 || y + dy[i] > 400) continue;
			unsafe[x + dx[i]][y + dy[i]] = true;
		}
	}
	sort(meteors, meteors + M, [](Point a, Point b) { return a.t < b.t; });

	memset(visited, -1, sizeof(visited));

	visited[0][0] = 0;
	q.push({0, 0, 0});

	int safe = -1;

	int tmp = 0;
	while (tmp < M && meteors[tmp].t == 0) {
		Point cur = meteors[tmp++];

		bool fail = false;

		if (cur.x == 0 && cur.y == 0) fail = true;
		for (int i = 0; i < 4; i++) {
			if (cur.x + dx[i] == 0 && cur.y + dy[i] == 0) fail = true;
		}

		if (fail) {
			printf("-1\n");
			return 0;
		}
	}

	while (!q.empty()) {
		Point cur = q.front(); q.pop();

		if (!unsafe[cur.x][cur.y]) {
			safe = cur.t;
			break;
		}

		while (front < M && meteors[front].t <= cur.t + 1) {
			Point meteor = meteors[front++];

			destroyed[meteor.x][meteor.y] = true;
			for (int i = 0; i < 4; i++) {
				if (meteor.x + dx[i] < 0 || meteor.y + dy[i] < 0 ||
						meteor.x + dx[i] > 400 || meteor.y + dy[i] > 400) continue;
				destroyed[meteor.x + dx[i]][meteor.y + dy[i]] = true;
			}
		}


		for (int i = 0; i < 4; i++) {
			Point next = {cur.x + dx[i], cur.y + dy[i], cur.t + 1};

			if (next.x < 0 || next.y < 0 ||
					next.x > 400 || next.y > 400) continue;
			if (visited[next.x][next.y] == next.t) continue;
			if (destroyed[next.x][next.y]) continue;

			visited[next.x][next.y] = next.t;
			q.push(next);
		}
		{
			Point next = {cur.x, cur.y, cur.t + 1};

			if (visited[next.x][next.y] == next.t) continue;
			if (destroyed[next.x][next.y]) continue;

			visited[next.x][next.y] = next.t;
			q.push(next);
		}
	}

	printf("%d\n", safe);

	return 0;
}
