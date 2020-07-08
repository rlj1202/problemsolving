#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

queue<int> q;
int visited[1000006];

int main() {
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	memset(visited, -1, sizeof(visited));

	visited[S] = 0;
	q.push(S);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == G) break;

		if (cur + U <= F && visited[cur + U] == -1) {
			visited[cur + U] = visited[cur] + 1;
			q.push(cur + U);
		}
		if (cur - D >= 1 && visited[cur - D] == -1) {
			visited[cur - D] = visited[cur] + 1;
			q.push(cur - D);
		}
	}

	if (visited[G] != -1) printf("%d\n", visited[G]);
	else printf("use the stairs\n");

	return 0;
}
