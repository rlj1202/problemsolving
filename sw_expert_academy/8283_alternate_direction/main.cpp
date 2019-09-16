#include <cstdio>
#include <cstring>

struct Point { int x, y, dir; };

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int visited[202][202][4];

Point queue[200005];
int front, rear;

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		Point s, e;
		scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);

		memset(visited, -1, sizeof(visited));
		front = rear = 0;

		for (int dir = 0; dir < 4; dir++) {
			queue[rear++] = {s.x, s.y, dir};
			visited[s.x + 100][s.y + 100][dir] = 0;
		}

		while (rear - front) {
			Point cur = queue[front++];
			
			if (cur.x == e.x && cur.y == e.y) break;

			for (int i = -1; i < 2; i += 2) {
				int ndir = cur.dir + i;
				if (ndir < 0) ndir += 4;
				if (ndir >= 4) ndir -= 4;

				Point next = {cur.x + dx[ndir], cur.y + dy[ndir], ndir};

				if (next.x < -100 || next.y < -100 ||
						next.x > 100 || next.y > 100) continue;
				if (visited[next.x + 100][next.y + 100][next.dir] != -1) continue;
				
				visited[next.x + 100][next.y + 100][next.dir] =
					visited[cur.x + 100][cur.y + 100][cur.dir] + 1;
				queue[rear++] = next;
			}
		}

		int result = 0;
		for (int dir = 0; dir < 4; dir++) {
			int tmp = visited[e.x + 100][e.y + 100][dir];
			if (result < tmp) result = tmp;
		}

		printf("#%d %d\n", t, result);
	}

	return 0;
}
