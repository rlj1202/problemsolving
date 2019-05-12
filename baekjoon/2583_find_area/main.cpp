#include <iostream>
#include <algorithm>

using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int M, N, K;
int grid[102][102];
int visited[102][102];

pair<int, int> queue[10004];
int front, rear;

int main() {
	scanf("%d %d %d", &M, &N, &K);

	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
			grid[y][x] = 1;
		}
	}

	for (int k = 0; k < K; k++) {
		int x1, y1;
		int x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int width = x2 - x1;
		int height = y2 - y1;

		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				grid[y1 + 1 + h][x1 + 1 + w] = 2;
			}
		}
	}

	int areas[10004];
	int arealen = 0;

	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
			if (visited[y][x] || grid[y][x] != 1) continue;

			int area = 0;

			front = rear = 0;
			queue[rear++] = {y, x};
			visited[y][x] = 1;
			area++;

			while (rear - front > 0) {
				pair<int, int> cur = queue[front++];

				for (int i = 0; i < 4; i++) {
					pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};

					if (!visited[next.first][next.second] && grid[next.first][next.second] == 1) {
						visited[next.first][next.second] = 1;
						queue[rear++] = next;
						area++;
					}
				}
			}

			areas[arealen++] = area;
		}
	}

	sort(areas, areas + arealen);

	printf("%d\n", arealen);
	for (int i = 0; i < arealen; i++) {
		printf("%d ", areas[i]);
	}
	printf("\n");

	return 0;
}
