#include <iostream>
#include <utility>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};
const char dirs[] = {'N', 'W', 'S', 'E'};

int N, M;
char grid[1003][1003];
int visited[1003][1003];

pair<int, int> queue[1000006];
int front, rear;

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		char raw[1003];
		scanf("%s", raw);
		for (int m = 1; m <= M; m++) grid[n][m] = raw[m - 1];
	}

	int result = 0;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (visited[r][c]) continue;

			front = rear = 0;
			queue[rear++] = make_pair(r, c);

			while (rear - front > 0) {
				pair<int, int> cur = queue[front++];
				char dir = grid[cur.first][cur.second];

				visited[cur.first][cur.second] = 1;

				for (int i = 0; i < 4; i++) {
					pair<int, int> next = make_pair(cur.first + dr[i], cur.second + dc[i]);
					if (dirs[i] == grid[next.first][next.second] && !visited[next.first][next.second]) {
						queue[rear++] = next;
					}
				}

				pair<int, int> next = cur;

				if (dir == 'N') {
					next.first--;
				} else if (dir == 'S') {
					next.first++;
				} else if (dir == 'W') {
					next.second--;
				} else if (dir == 'E') {
					next.second++;
				}

				if (grid[next.first][next.second] != 0 && !visited[next.first][next.second]) {
					queue[rear++] = next;
				}
			}

			result++;
		}
	}

	printf("%d\n", result);

	return 0;
}
