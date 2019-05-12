#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Point { int r, c; };

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int N;
int grid[102][102];

queue<Point> q;
int out[102][102];
int lower[102][102];
int upper[102][102];

int main() {
	// init
	memset(lower, -1, sizeof(lower));
	
	// read input
	scanf("%d", &N);
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++)
			scanf("%d", &grid[r][c]);
	}

	//
	lower[1][1] = upper[1][1] = grid[1][1];
	q.push({1, 1});

	while (true) {
		Point cur = q.front(); q.pop();
		if (out[cur.r][cur.c]) continue;
		out[cur.r][cur.c] = true;

		for (int i = 0; i < 4; i++) {

		}
	}

	// print result
	int result = 0;
	printf("%d\n", result);

	return 0;
}
