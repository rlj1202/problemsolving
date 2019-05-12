#include <iostream>
#include <utility>

using namespace std;

int N, M;
int map[1003][1003];
pair<int, int> indices[4003];
int out[4003];

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			scanf("%d", &map[n][m]);
		}
	}

	for (int n = 1; n <= N; n++) {
		indices[n + 0] = make_pair(n, 0);
		indices[2*N+M+1 - n] = make_pair(n, M+1);
		map[n][0] = n + 0;
		map[n][M+1] = 2*N+M+1 - n;
	}
	for (int m = 1; m <= M; m++) {
		indices[N + m] = make_pair(N+1, m);
		indices[2*(N+M)+1 - m] = make_pair(0, m);
		map[N+1][m] = N + m;
		map[0][m] = 2*(N+M)+1 - m;
	}

	for (int i = 1; i <= 2*(N + M); i++) {
		if (out[i] != 0) continue;

		int deltaN;
		int deltaM;
		if (1 <= i && i <= N) {
			deltaN = 0;
			deltaM = 1;
		} else if (N < i && i <= N+M) {
			deltaN = -1;
			deltaM = 0;
		} else if (N+M < i && i <= 2*N+M) {
			deltaN = 0;
			deltaM = -1;
		} else {
			deltaN = 1;
			deltaM = 0;
		}

		int n = indices[i].first;
		int m = indices[i].second;

		do {
			n += deltaN;
			m += deltaM;

			if (map[n][m] == 1) {
				int tmp = deltaN;
				deltaN = -deltaM;
				deltaM = -tmp;
			}
		} while (1 <= n && n <= N && 1 <= m && m <= M);

		int dest = map[n][m];
		out[i] = dest;
		out[dest] = i;
	}

	//
	
	for (int i = 1; i <= 2*(N + M); i++) {
		printf("%d ", out[i]);
	}
	printf("\n");

	return 0;
}
