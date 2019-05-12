#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int map[502][502];
int visited[502][502];
pair<int, int> queue[400005];
int front, rear;

const int INF = 0x3f3f3f3f;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int maxDays;

int main() {
	scanf("%d", &N);

	memset(map, INF, sizeof(map));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cur = map[i][j];

			bool leaf = true;
			for (int k = 0; k < 4; k++)
				if (cur > map[i + dx[k]][j + dy[k]]) leaf = false;

			if (leaf) {
				queue[rear++] = make_pair(i, j);
				visited[i][j] = 1;
			}
		}
	}

	maxDays = 1;
	
	while (rear - front > 0) {
		pair<int, int> cur = queue[front++];

		for (int i = 0; i < 4; i++) {
			int row = cur.first + dx[i];
			int col = cur.second + dy[i];

			if (map[row][col] == INF) continue;

			if (map[cur.first][cur.second] < map[row][col]) {
				if (visited[row][col] < visited[cur.first][cur.second] + 1) {
					queue[rear++] = make_pair(row, col);
					visited[row][col] = visited[cur.first][cur.second] + 1;

					maxDays = max(maxDays, visited[row][col]);
				}
			}
		}
	}

	printf("################################################################################\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	printf("################################################################################\n");
	
	printf("%d\n", maxDays);

	return 0;
}
