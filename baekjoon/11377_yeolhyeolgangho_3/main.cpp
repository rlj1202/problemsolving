#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[1003];

int employee[1003][2];
int tasks[1003][2];

bool visited[1003][2];

int result;

bool find_match(int n, int i) {
	visited[n][i] = true;

	for (int next : adj[n]) {
		if (tasks[next][0] == -1 ||
				(!visited[tasks[next][0]][tasks[next][1]] &&
				 find_match(tasks[next][0], tasks[next][1]))) {
			employee[n][i] = next;
			tasks[next][0] = n;
			tasks[next][1] = i;
			return true;
		}
	}

	return false;
}

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int n = 0; n < N; n++) {
		int tasks;
		scanf("%d", &tasks);

		while (tasks--) {
			int task;
			scanf("%d", &task);
			adj[n].push_back(task);
		}
	}

	memset(employee, -1, sizeof(employee));
	memset(tasks, -1, sizeof(tasks));
	for (int n = 0; n < N; n++) {
		if (employee[n][0] != -1) continue;

		memset(visited, false, sizeof(visited));
		if (find_match(n, 0)) result++;
	}
	for (int n = 0; n < N && K; n++) {
		if (employee[n][1] != -1) continue;
		
		memset(visited, false, sizeof(visited));
		if (find_match(n, 1)) {
			K--;
			result++;
		}
	}

	printf("%d\n", result);

	return 0;
}
