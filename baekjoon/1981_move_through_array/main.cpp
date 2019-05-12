#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
	int row;
	int col;
	int delta;
};

struct Compare {
	bool operator() (const Node &a, const Node &b) {
		return a.delta > b.delta;
	}
};

int N;
int map[102][102];

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int low[102][102];
int high[102][102];
int visited[102][102];
priority_queue<Node, vector<Node>, Compare> q;

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	low[1][1] = map[1][1];
	high[1][1] = map[1][1];
	visited[1][1] = 1;
	q.push(Node{1, 1, 0});

	while (!q.empty()) {
		Node cur = q.top(); q.pop();
		if (cur.row == N && cur.col == N)
			break;

		int curLow = low[cur.row][cur.col];
		int curHigh = high[cur.row][cur.col];

		for (int i = 0; i < 4; i++) {
			int row = cur.row + dr[i];
			int col = cur.col + dc[i];
			if (row < 1 || N < row) continue;
			if (col < 1 || N < col) continue;

			int newLow = low[row][col];
			int newHigh = high[row][col];

			if (!visited[row][col]) {
				newLow = map[row][col];
				newHigh = map[row][col];
			}

			newLow = min(curLow, newLow);
			newHigh = max(curHigh, newHigh);

			low[row][col] = newLow;
			high[row][col] = newHigh;

			if (!visited[row][col]) {
				visited[row][col] = 1;
				q.push(Node{row, col, high[row][col] - low[row][col]});
			}
		}
	}

	printf("%d\n", high[N][N] - low[N][N]);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (!visited[r][c]) printf("(-,-)");
			else printf("(%d,%d)", low[r][c], high[r][c]);
		}
		printf("\n");
	}

	return 0;
}
