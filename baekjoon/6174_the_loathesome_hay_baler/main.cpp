#include <cstdio>
#include <algorithm>

using namespace std;

struct Roller { int x, y, r; };

Roller rollers[1050];

int origin, target;

int visited[1050];
double speed[1050];
int droven_by[1050];
int queue[1050], front, rear;

bool does_meets(Roller &a, Roller &b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	int dist_square = dx*dx + dy*dy;

	return dist_square == (a.r + b.r) * (a.r + b.r);
}

int main() {
	int N, X, Y;
	scanf("%d %d %d", &N, &X, &Y);
	for (int n = 0; n < N; n++) {
		int x, y, r;
		scanf("%d %d %d", &x, &y, &r);
		rollers[n] = {x, y, r};

		if (x == 0 && y == 0) origin = n;
		if (x == X && y == Y) target = n;
	}

	visited[origin] = true;
	speed[origin] = 10000;
	droven_by[origin] = -1;
	queue[rear++] = origin;

	while (rear - front) {
		int cur = queue[front++];

		for (int next = 0; next < N; next++) {
			if (visited[next]) continue;

			if (does_meets(rollers[cur], rollers[next])) {
				visited[next] = true;
				speed[next] = -speed[cur] * rollers[cur].r / rollers[next].r;
				droven_by[next] = cur;
				queue[rear++] = next;
			}
		}
	}

	double total = 0;

	int cur = target;
	while (cur != -1) {
		total += abs(speed[cur]);
		cur = droven_by[cur];
	}

	printf("%d\n", (int) total);

	return 0;
}
