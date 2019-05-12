#include <iostream>
#include <cstring>

using namespace std;

int N, K;

pair<int, int> queue[1000006];
int front, rear;

int mintime[500005][2];

int main() {
	scanf("%d %d", &N, &K);

	memset(mintime, -1, sizeof(mintime));

	mintime[N][N % 2] = 0;
	queue[rear++] = {N, 0};

	while (rear - front) {
		pair<int, int> cur = queue[front++]; // position, time

		int t = (cur.second + 1) % 2;

		int l = cur.first - 1;
		int r = cur.first + 1;
		int jmp = cur.first * 2;

		if (l >= 0 && mintime[l][t] == -1) {
			mintime[l][t] = cur.second + 1;
			queue[rear++] = {l, cur.second + 1};
		}
		if (r <= 500000 && mintime[r][t] == -1) {
			mintime[r][t] = cur.second + 1;
			queue[rear++] = {r, cur.second + 1};
		}
		if (jmp <= 500000 && mintime[jmp][t] == -1) {
			mintime[jmp][t] = cur.second + 1;
			queue[rear++] = {jmp, cur.second + 1};
		}
	}

	bool found = false;
	int t = 0;
	int target = K;
	while ((target += t) <= 500000) {
		if (mintime[target][t % 2] <= t) {
			found = true;
			break;
		}

		t++;
	}

	if (found) printf("%d\n", t);
	else printf("%d\n", -1);

	return 0;
}
