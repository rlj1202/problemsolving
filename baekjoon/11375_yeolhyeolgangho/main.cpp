#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, M;
vector<int> adj[2003];

int capacities[2003][2003];
int flows[2003][2003];

int queue[1000006];
int parent[1000006];
int front, rear;

bool visited[2003];

int max_tasks;

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		int tasks;
		scanf("%d", &tasks);

		for (int t = 0; t < tasks; t++) {
			int task;
			scanf("%d", &task);

			capacities[n][task + N] = 1;
			capacities[task + N][n] = 1;
			adj[n].push_back(task + N);
			adj[task + N].push_back(n);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		capacities[0][i] = 1;
		capacities[i][0] = 1;
		adj[0].push_back(i);
	}
	for (int i = 1; i <= M; i++) {
		capacities[N + M + 1][i + N] = 1;
		capacities[i + N][N + M + 1] = 1;
		adj[i + N].push_back(N + M + 1);

	}

	bool blocked = false;

	while (!blocked) {
		memset(visited, 0, sizeof(visited));
		front = rear = 0;

		visited[0] = true;
		queue[rear] = 0;
		parent[rear] = -1;
		rear++;

		while (rear - front > 0 && queue[front] != N + M + 1) {
			int cur = queue[front];

			for (int next : adj[cur]) {
				if (visited[next]) continue;

				if (capacities[cur][next] - flows[cur][next] <= 0) continue;

				visited[next] = true;
				queue[rear] = next;
				parent[rear] = front;
				rear++;
			}

			front++;
		}

		if (rear - front > 0 && queue[front] == N + M + 1) {
			int mincap = INF;

			int cur = front;
			while (parent[cur] != -1) {
				int a = queue[parent[cur]];
				int b = queue[cur];
				mincap = min(mincap, capacities[a][b] - flows[a][b]);
				cur = parent[cur];
			}

			cur = front;
			while (parent[cur] != -1) {
				int a = queue[parent[cur]];
				int b = queue[cur];
				flows[a][b] += mincap;
				flows[b][a] -= mincap;
				cur = parent[cur];
			}

			max_tasks += mincap;
		} else {
			blocked = true;
		}
	}

	printf("%d\n", max_tasks);

	return 0;
}
