#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct point { int r, c; };

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int T;

int N;
char grid[22][22]; // one-base indexing

queue<point> q;
int area[22][22]; // one-base indexing
int areaId;

int count(int r, int c, int dr, int dc) {
	if (dr == 1 && dc == 1) return 0;

	int flag[26];
	for (int i = 0; i < 26; i++) flag[i] = 0;
	int areas[26];
	int diffAlphas = 0;

	for (int R = r; R < r + dr; R++) {
		for (int C = c; C < c + dc; C++) {
			if (flag[grid[R][C] - 'A'] == 0) {
				flag[grid[R][C] - 'A'] = 1;
				diffAlphas++;

				areas[grid[R][C] - 'A'] = area[R][C];
			}
		}
	}

	printf("(%d %d %d %d), diffalpha : %d\n", r, c, dr, dc, diffAlphas);

	if (diffAlphas < 2) return 0;
	if (diffAlphas > 2) {
		return count(r, c, dr - 1, dc)
			+ count(r + 1, c, dr - 1, dc)
			+ count(r, c, dr, dc - 1)
			+ count(r, c + 1, dr, dc - 1);
	}
	
	return 0;
}

int main() {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		// init
		setbuf(stdout, NULL); // for codeground
		
		memset(area, 0, sizeof(area));
		areaId = 0;
		scanf("%d", &N);
		for (int r = 1; r <= N; r++) {
			char raw[22];
			scanf("%s", raw);
			for (int c = 1; c <= N; c++)
				grid[r][c] = raw[c - 1];
		}

		// make areas and numbering each pertition using BFS
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				if (area[r][c] != 0) continue;

				area[r][c] = ++areaId;
				q.push(point{r, c});

				while (!q.empty()) {
					point cur = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						point next = {cur.r + dr[i], cur.c + dc[i]};
						if (grid[cur.r][cur.c] == grid[next.r][next.c] && area[next.r][next.c] == 0) {
							area[next.r][next.c] = area[cur.r][cur.c];
							q.push(next);
						}
					}
				}
			}
		}

		printf("################################################################################\n");
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) printf("%c%-2d ", grid[r][c], area[r][c]);
			printf("\n");
		}
		printf("################################################################################\n");

		// print result
		int result = count(1, 1, N, N);

		printf("Case #%d\n", t);
		printf("%d\n", result);
	}

	return 0;
}
