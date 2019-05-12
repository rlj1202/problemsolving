#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> adj[32004];
int indegrees[32004];

int stack[32004];
int top;

int main() {
	scanf("%d %d", &N, &M);

	for (int m = 1; m <= M; m++) {
		int a, b;
		scanf("%d %d", &a, &b);

		adj[a].push_back(b);
		indegrees[b]++;
	}

	for (int n = 1; n <= N; n++) {
		if (indegrees[n] == 0) stack[top++] = n;
	}

	while (top > 0) {
		int cur = stack[--top];
		printf("%d ", cur);

		for (int next : adj[cur]) {
			if (--indegrees[next] == 0) {
				stack[top++] = next;
			}
		}
	}
	printf("\n");

	return 0;
}
