#include <cstdio>

struct Roller {
	int x, y, r;
};

Roller rollers[1080];
bool visited[1080];
bool drive[1080];

int origin;

int queue[1080], front, rear;

bool does_meets(Roller &a, Roller &b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	int dist_square = dx * dx + dy * dy;

	return dist_square == (a.r + b.r) * (a.r + b.r);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		rollers[n] = {x, y, r};

		if (x == 0 && y == 0) origin = n;
	}

	visited[origin] = true;
	queue[rear++] = origin;

	while (rear - front) {
		int cur = queue[front++];

		for (int next = 0; next < N; next++) {
			if (visited[next]) continue;

			if (does_meets(rollers[cur], rollers[next])) {
				visited[next] = true;
				queue[rear++] = next;
				drive[cur] = true;
			}
		}
	}

	for (int n = 0; n < N; n++) {
		if (visited[n] && !drive[n]) {
			Roller answer = rollers[n];
			printf("%d %d\n", answer.x, answer.y);
			break;
		}
	}

	return 0;
}
