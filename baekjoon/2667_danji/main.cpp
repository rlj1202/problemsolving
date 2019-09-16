#include <cstdio>
#include <algorithm>

using namespace std;

struct Point { int r, c; };

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

char grid[27][27];
bool visited[27][27];

Point q[702];
int front, rear;

int results[702];
int resultslen;

int main() {
	int N;
	scanf("%d", &N);
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			scanf(" %c", &grid[r][c]);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (visited[r][c] || grid[r][c] != '1') continue;

			front = rear = 0;

			visited[r][c] = true;
			q[rear++] = {r, c};

			int count = 0;

			while (rear - front) {
				Point cur = q[front++];
				count++;

				for (int i = 0; i < 4; i++) {
					Point next = {cur.r + dr[i], cur.c + dc[i]};
					if (grid[next.r][next.c] != '1' || visited[next.r][next.c]) continue;

					visited[next.r][next.c] = true;
					q[rear++] = next;
				}
			}

			results[resultslen++] = count;
		}
	}

	sort(results, results + resultslen);
	printf("%d\n", resultslen);
	for (int i = 0; i < resultslen; i++) printf("%d\n", results[i]);

	return 0;
}
