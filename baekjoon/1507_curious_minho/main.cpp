#include <iostream>
#include <algorithm>

using namespace std;

int N;
int adj[22][22];

int main() {
	scanf("%d", &N);

	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++)
			scanf("%d", &adj[a][b]);
	}

	//
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (adj[j][i] != 0 && adj[i][k] != 0 && adj[j][k] != 0) {
					if (adj[j][k] == adj[j][i] + adj[i][k]) {
						adj[j][k] = 0;
					} else if (adj[j][k] > adj[j][i] + adj[i][k]) {
						printf("-1");
						return 0;
					}
				}
			}
		}
	}

	//

	int total = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++)
			total += adj[i][j];
	}
	printf("%d", total);

	return 0;
}
