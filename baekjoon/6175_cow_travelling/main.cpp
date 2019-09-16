#include <cstdio>
#include <cstring>

struct Point { int r, c; };

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

char grid[102][102];
Point start, end;

int mem1[102][102];
int mem2[102][102];

int main() {
	int N, M, T;
	scanf("%d %d %d", &N, &M, &T);
	for (int n = 1; n <= N; n++) {
		scanf("%s", grid[n] + 1);
	}
	scanf("%d %d %d %d", &start.r, &start.c, &end.r, &end.c);

	int (*cur)[102][102] = &mem1;
	int (*next)[102][102] = &mem2;

	(*cur)[start.r][start.c] = 1;

	for (int t = 0; t < T; t++) {
		memset(*next, 0, sizeof(*next));

		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= M; c++) {
				for (int i = 0; i < 4; i++) {
					Point p = {r + dr[i], c + dc[i]};
					if (p.r < 1 || p.c < 1 ||
							p.r > N || p.c > M) continue;
					if (grid[p.r][p.c] == '*') continue;

					(*next)[p.r][p.c] += (*cur)[r][c];
				}
			}
		}

		int (*tmp)[102][102] = cur;
		cur = next;
		next = tmp;
	}

	printf("%d\n", (*cur)[end.r][end.c]);

	return 0;
}
