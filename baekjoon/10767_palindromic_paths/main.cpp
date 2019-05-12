#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
char grid[20][20];

char path[20];

int hashes[400005];
int hashlen;

bool g(int, int, int);

void f(int r, int c, int curR, int curC, int dist) {
	path[dist++] = grid[curR][curC];

	if (r == curR && c == curC) {
		if (g(r, c, 0)) {
			int hash = 0;
			for (int i = 0; i < N; i++) {
				hash *= 26;
				hash += path[i] - 'A';
			}
			hashes[hashlen++] = hash;
		}
		return;
	}

	if (curR + 1 <= r) f(r, c, curR + 1, curC, dist);
	if (curC + 1 <= c) f(r, c, curR, curC + 1, dist);
}

bool g(int curR, int curC, int dist) {
	if (curR == N && curC == N) return true;

	dist++;

	bool result = false;
	if (curR + 1 <= N && grid[curR + 1][curC] == path[N - dist - 1]) result |= g(curR + 1, curC, dist);
	if (!result && curC + 1 <= N && grid[curR][curC + 1] == path[N - dist - 1]) result |= g(curR, curC + 1, dist);
	return result;
}

int main() {
	scanf("%d", &N);

	for (int r = 1; r <= N; r++) {
		char raw[20];
		scanf("%s", raw);
		for (int c = 1; c <= N; c++) grid[r][c] = raw[c - 1];
	}

	for (int d = 1; d <= N; d++) {
		int r = N - d + 1;
		int c = d;
		f(r, c, 1, 1, 0);
	}

	sort(hashes, hashes + hashlen);

	int last = 0;
	int cnt = 0;
	for (int i = 0; i < hashlen; i++) {
		int cur = hashes[i];
		if (last != cur) {
			cnt++;
			last = cur;
		}
	}
	printf("%d\n", cnt);

	return 0;
}
