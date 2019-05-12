#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int K, N, M;
vector<int> adj[1003];

int cows[1003];

bool visited[1003];
int queue[1003];
int front, rear;

int main() {
	scanf("%d %d %d", &K, &N, &M);
	for (int k = 0; k < K; k++) {
		int pasture;
		scanf("%d", &pasture);
		cows[pasture]++;
	}
	for (int m = 0; m < M; m++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[b].push_back(a); // reverse the edge
	}

	int result = 0;

	for (int n = 1; n <= N; n++) {
		front = rear = 0;
		memset(visited, 0, sizeof(visited));

		visited[n] = true;
		queue[rear++] = n;

		int reachables = 0;

		while (rear - front > 0) {
			int cur = queue[front++];
			reachables += cows[cur];

			for (int next : adj[cur]) {
				if (visited[next]) continue;

				visited[next] = true;
				queue[rear++] = next;
			}
		}

		if (reachables == K) result++;
	}

	printf("%d\n", result);

	return 0;
}
