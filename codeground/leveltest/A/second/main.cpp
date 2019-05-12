#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

struct point { int r, c; };
struct square { int r, c, rlen, clen; };

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int T;

int N;
int grid[22][5][22];

queue<point> q;
vector<square> results;

bool contains(const square &a, const square &b) {
	return (a.r <= b.r && b.r + b.rlen <= a.r + a.rlen)
		&& (a.c <= b.c && b.c + b.clen <= a.c + a.clen);
}

void count(int r, int c, int rlen, int clen) {
	if (rlen <= 1 && clen <= 1) return;

	int tmp;

	tmp= clen;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;
	int len = 1 << log;

	int flag = 0;
	for (int R = r; R < r + rlen; R++)
		flag |= grid[R][log][c] | grid[R][log][c + clen - len];

	tmp = flag;
	int diffalphas = 0;
	while (tmp > 0) {
		diffalphas += (tmp & 1);
		tmp >>= 1;
	}

	if (diffalphas < 2) return;
	if (diffalphas > 2) {
		count(r, c, rlen - 1, clen);
		count(r + 1, c, rlen - 1, clen);
		count(r, c, rlen, clen - 1);
		count(r, c + 1, rlen, clen - 1);
		return;
	}

	// bfs
	int id = 0;
	int area[22][22];
	memset(area, 0, sizeof(area));

	for (int nr = r; nr < r + rlen; nr++) {
		for (int nc = c; nc < c + clen; nc++) {
			if (area[nr][nc] != 0) continue;

			area[nr][nc] = ++id;
			q.push(point{nr, nc});

			while (!q.empty()) {
				point cur = q.front(); q.pop();

				for (int i = 0; i < 4; i++) {
					point next = {cur.r + dr[i], cur.c + dc[i]};

					if (r <= next.r && next.r < r + rlen
							&& c <= next.c && next.c < c + clen
							&& grid[cur.r][0][cur.c] == grid[next.r][0][next.c]
							&& area[next.r][next.c] == 0) {
						area[next.r][next.c] = area[cur.r][cur.c];
						q.push(next);
					}
				}
			}
		}
	}

	if (id == 3) {
		results.push_back(square{r, c, rlen, clen});
		return;
	}

	return;
}

int main() {
	// init
	scanf("%d", &T);
	setbuf(stdout, NULL);

	for (int t = 1; t <= T; t++) {
		// read input
		scanf("%d", &N);
		for (int r = 1; r <= N; r++) {
			char raw[22];
			scanf("%s", raw);
			for (int c = 1; c <= N; c++)
				grid[r][0][c] = 1 << (raw[c - 1] - 'A');
		}
		results.clear();

		// sqrt decomposition ?
		int tmp = N;
		int log = 0;
		while ((tmp >>= 1) != 0) log++;

		for (int r = 1; r <= N; r++) {
			for (int l = 1; l <= log; l++) {
				int prevlen = 1 << (l - 1);
				int len = 1 << l;
				
				for (int c = 1; c <= N - len + 1; c++) {
					int flag = 0;
					flag |= grid[r][l - 1][c];
					flag |= grid[r][l - 1][c + prevlen];
					grid[r][l][c] = flag;
				}
			}
		}

		// print result
		count(1, 1, N, N);

		int *deleted = (int*) malloc(sizeof(int) * results.size());
		for (int i = 0; i < (int) results.size(); i++) deleted[i] = 0;
		for (int i = 0; i < (int) results.size(); i++) {
			if (deleted[i] == 0) {
				for (int j = i + 1; j < (int) results.size(); j++) {
					if (deleted[j] == 0 && contains(results.at(j), results.at(i))) {
						deleted[i] = 1;
						break;
					}
				}
			}
		}

		int answer = 0;
		for (int i = 0; i < (int) results.size(); i++) {
			if (deleted[i] == 0) answer++;
		}

		free(deleted);

		printf("Case #%d\n", t);
		printf("%d\n", answer);
	}

	return 0;
}
