#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[502];
int result;

bool visited[502];

int queue[502];
int front, rear;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	visited[1] = true;
	queue[rear++] = 1;

	int times = 2;
	while (rear - front && times--) {
		int end = rear;
		while (end - front) {
			int cur = queue[front++];

			for (int next : adj[cur]) {
				if (!visited[next]) {
					visited[next] = true;
					queue[rear++] = next;
					result++;
				}
			}
		}
	}

	printf("%d\n", result);
	
	return 0;
}
