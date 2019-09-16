#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[3003];
bool finished[3003];

priority_queue<int> groups;
int maxgroupsize;

int check(int n) {
	finished[n] = true;
	int count = 1;

	for (int next : adj[n]) {
		if (finished[next]) continue;
		count += check(next);
	}

	return count;
}

int main() {
	// read input
	int N, M;
	scanf("%d %d", &N, &M);

	while (M--) {
		int S, E;
		scanf("%d %d", &S, &E);
		adj[S].push_back(E);
	}

	// add highway roads
	for (int n = 1; n <= N - 1; n++) {
		adj[n].push_back(n + 1);
	}

	// get sizes of sccs in the graph
	for (int n = N; n >= 1; n--) {
		if (finished[n]) continue;
		int groupsize = check(n);
		maxgroupsize = max(maxgroupsize, groupsize);
		groups.push(groupsize);
	}

	// TODO combine some numbers in groups array so that all elements in groups
	// are same to a particular integer number.
	// ex) if groups = [1, 1, 2], then it will be groups = [2, 2]
	
	while (groups.top() != maxgroupsize) {
		int a = groups.top(); groups.pop();
		int b = groups.top(); groups.pop();
		int c = a + b;
		maxgroupsize = max(maxgroupsize, c);
		groups.push(c);
	}

	// print result
	printf("%d\n", (int) groups.size());

	return 0;
}
