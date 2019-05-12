#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, Q;
int times[502];
priority_queue<pair<int, int>> stops;
long long dist[502][502];
int time[502][502];

int main() {
	scanf("%d %d %d", &N, &M, &Q);

	for (int n = 1; n <= N; n++) {
		int time;
		scanf("%d", &time);
		times[n] = time;
		stops.push(make_pair(-time, n));
	}

	memset(dist, 63, sizeof(dist));
	memset(time, 63, sizeof(time));
	for (int m = 1; m <= M; m++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		dist[a][b] = min(dist[a][b], (long long) c);
		dist[b][a] = min(dist[b][a], (long long) c);

		int t = max(times[a], times[b]);
		time[a][b] = t;
		time[b][a] = t;
	}

	while (!stops.empty()) {
		pair<int, int> stop = stops.top(); stops.pop();
		int k = stop.second;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][k] == 0x3f3f3f3f || dist[k][j] == 0x3f3f3f3f) continue;

				long long newDist = dist[i][k] + dist[k][j];
				int newTime = max(time[i][k], time[k][j]);

				long long curCost = dist[i][j] + time[i][j];
				long long newCost = newDist + newTime;

				if (curCost > newCost) {
					dist[i][j] = newDist;
					time[i][j] = newTime;
				}
			}
		}
	}

	while (Q--) {
		int S, T;
		scanf("%d %d", &S, &T);

		long long result = dist[S][T] + time[S][T];
		if (dist[S][T] == 0x3f3f3f || time[S][T] == 0x3f3f3f3f) result = -1;
		printf("%lld\n", result);
	}
	
	return 0;
}
