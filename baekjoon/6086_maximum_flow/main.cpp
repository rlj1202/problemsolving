/*
 * Ford-Fulkerson Algorithm
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int N;

vector<int> adj[52];
int capacities[52][52];
int flows[52][52];

int stack[52];
int stacksize;
bool out[52];

int maximum_flow;

int main() {
	// read the number of edges.
	scanf("%d", &N);

	// read edges and if there is multiple edges
	// between the two vertices, choose the minimum cap.
	for (int n = 0; n < N; n++) {
		char a, b;
		int cap;
		scanf(" %c %c %d", &a, &b, &cap);

		if (a <= 'Z') a -= 'A';
		else a -= 'a' - 26;

		if (b <= 'Z') b -= 'A';
		else b -= 'a' - 26;

		adj[a].push_back(b);
		adj[b].push_back(a);

		capacities[a][b] += cap;
		capacities[b][a] += cap;
	}

	// find path A -> Z using dfs until we cannot.
	bool blocked = false;

	while (!blocked) {
		memset(out, 0, sizeof(out));
		out[0] = true;

		stacksize = 0;
		stack[stacksize++] = 0;

		while (stacksize) {
			int cur = stack[stacksize - 1]; // stack.top

			if (cur == 25) break;

			bool found = false;

			for (int next : adj[cur]) {
				if (out[next]) continue;
				if (capacities[cur][next] - flows[cur][next] <= 0) continue;

				found = true;

				out[next] = true;
				stack[stacksize++] = next;
				break;
			}

			if (!found) stacksize--;
		}

		if (stacksize && stack[stacksize - 1] == 25) {
			int mincap = INF;

			for (int i = 0; i < stacksize - 1; i++) {
				int a = stack[i];
				int b = stack[i + 1];
				mincap = min(mincap, capacities[a][b] - flows[a][b]);

				out[b] = false;
			}

			for (int i = 0; i < stacksize - 1; i++) {
				int a = stack[i];
				int b = stack[i + 1];

				flows[a][b] += mincap;
				flows[b][a] -= mincap;
			}

			maximum_flow += mincap;
		} else {
			blocked = true;
		}
	}

	// print result
	printf("%d\n", maximum_flow);

	return 0;
}
