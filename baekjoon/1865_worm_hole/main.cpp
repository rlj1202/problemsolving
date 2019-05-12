#include <iostream>

#define INF 1000000009

int T;
int N, M, W;

int adj[502][502];
int shortest[502];

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &N, &M, &W);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				adj[i][j] = INF;
		}
		for (int i = 1; i <= M; i++) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);

			if (adj[s][e] > t) {
				adj[s][e] = t;
				adj[e][s] = t;
			}
		}

		for (int i = 1; i <= W; i++) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);

			if (adj[s][e] > -t) adj[s][e] = -t;
		}

		//
		
		for (int i = 1; i <= N; i++) shortest[i] = INF;
		shortest[1] = 0;

		for (int v = 1; v <= N; v++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (shortest[i] != INF && shortest[j] > shortest[i] + adj[i][j]) {
						shortest[j] = shortest[i] + adj[i][j];
					}
				}
			}
		}

		bool cyclic = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (shortest[j] > shortest[i] + adj[i][j]) {
					cyclic = true;
					goto outer;
				}
			}
		}
outer:

		printf("%s\n", cyclic ? "YES" : "NO");
	}

	return 0;
}
