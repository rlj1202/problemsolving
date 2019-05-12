#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K;

int V, E;
vector<int> adj[20004];

vector<int> partitions[20004];
int cnt;

bool isolated(vector<int> partition) {
	for (int a : partition) {
		for (int b : partition) {
			if (a != b) {
				for (int edge : adj[a]) {
					if (edge == b) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main() {
	scanf("%d", &K);

	while (K--) {
		scanf("%d %d", &V, &E);

		for (int e = 1; e <= E; e++) {
			int a, b;
			scanf("%d %d", &a, &b);

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int v = 1; v <= V; v++) {
			bool updated = false;
			for (int p = 0; p < cnt; p++) {
				for (int element : partitions[p]) {
					bool connected = false;
					for (int edge : adj[element]) {
						if ((connected = (edge == v))) break;
					}

					if (!connected) {
						updated = true;
						break;
					}
				}

				if (updated) {
					partitions[p].push_back(v);
					break;
				}
			}

			if (!updated) {
				partitions[cnt++].push_back(v);
			}
		}

		if (cnt > 2) {
			printf("NO\n");
			continue;
		}

		bool bipartition = isolated(partitions[0]);
		if (cnt == 1) {
			bipartition &= partitions[0].size() > 1;
		} else {
			bipartition &= isolated(partitions[1]);
		}

		if (bipartition) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

		/*
		printf("################################################################################\n");
		for (int p = 0; p < cnt; p++) {
			printf("[%d]:", p);
			for (int element : partitions[p]) {
				printf(" %d,", element);
			}
			printf("\n");
		}
		printf("################################################################################\n");
		*/

		for (int p = 0; p < cnt; p++) {
			partitions[p].clear();
		}
		cnt = 0;

		for (int v = 1; v <= V; v++) {
			adj[v].clear();
		}
	}

	return 0;
}
