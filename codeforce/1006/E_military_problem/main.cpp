#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<int> adj[200005];

int order[200005];
int indices[200005];
int length[200005];
int curIndex = 1;

int dfs(int officer) {
	order[curIndex] = officer;
	indices[officer] = curIndex++;

	int len = 1;
	for (int child : adj[officer]) len += dfs(child);

	return length[officer] = len;
}

int main() {
	// read input
	scanf("%d %d", &N, &Q);

	for (int child = 2; child <= N; child++) {
		int parent;
		scanf("%d", &parent);

		adj[parent].push_back(child); // make adjacent lsit
	}

	dfs(1); // construct array

	while (Q--) {
		// receive query
		int officer, offset;
		scanf("%d %d", &officer, &offset);

		// print result
		int orderIndex = indices[officer] + offset - 1;
		if (orderIndex <= N && offset <= length[officer]) printf("%d\n", order[orderIndex]);
		else printf("%d\n", -1);
	}

	return 0;
}
