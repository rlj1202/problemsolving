#include <iostream>
#include <vector>

using namespace std;

int N;
int parent[60];
int toDelete;

int root;
vector<int> children[60];

int countLeaves(int node) {
	if (node == toDelete) return 0;

	int sum = 0;
	for (int child : children[node]) sum += countLeaves(child);
	if (sum == 0) return 1;

	return sum;
}

int main() {
	scanf("%d", &N);
	for (int child = 0; child < N; child++) {
		scanf("%d", parent + child);

		if (parent[child] == -1) root = child;
		else children[parent[child]].push_back(child);
	}
	scanf("%d", &toDelete);

	printf("%d\n", countLeaves(root));

	return 0;
}
