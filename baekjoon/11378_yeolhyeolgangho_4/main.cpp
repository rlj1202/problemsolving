#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> adj[1003];

int tasks[1003];
bool visited[1003];

int result;

bool find_match(int n) {
	visited[n] = true;

	for (int next : adj[n]) {
		if (tasks[next] == -1 || (!visited[tasks[next]] && find_match(tasks[next]))) {
			tasks[next] = n;
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

	memset(tasks, -1, sizeof(tasks));
	for (int n = 0; n < N; n++) {
		memset(visited, false, sizeof(visited));
		if (find_match(n)) result++;
	}
	bool updated = true;
	while (K && updated) {
		updated = false;

		for (int n = 0; n < N && K; n++) {
			memset(visited, false, sizeof(visited));
			if (find_match(n)) {
				updated = true;
				K--;
				result++;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
