#include <iostream>
#include <vector>

using namespace std;

int N;
int adj[1003][1003];
int edges;

int circuit[500005];
int length;

bool find(int usedEdges) {
	if (usedEdges == edges && circuit[0] == circuit[usedEdges]) {
		return true;
	}

	int v = circuit[usedEdges];

	for (int i = 1; i <= N; i++) {
		if (adj[v][i]) {
			adj[v][i]--;
			adj[i][v]--;

			circuit[usedEdges + 1] = i;
			if (find(usedEdges + 1)) {
				return true;
			}

			adj[v][i]++;
			adj[i][v]++;
		}
	}

	return false;
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &adj[i][j]);
			sum += adj[i][j];
		}

		if (sum % 2 == 1) {
			printf("-1\n");
			return 0;
		}

		edges += sum;
	}
	edges /= 2;

	for (int i = 1; i <= N; i++) {
		circuit[0] = i;
		if (find(0))
			break;
	}

	for (int i = 0; i < edges + 1; i++) {
		printf("%d ", circuit[i]);
	}
	printf("\n");

	return 0;
}
