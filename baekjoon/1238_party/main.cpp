#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1000000009

using namespace std;
int N, M, X;

vector<pair<int, int>> adj[1003];
vector<pair<int, int>> adjR[1003];

priority_queue<pair<int, int>> shortest;
int out[1003];

int toX[1003];
int fromX[1003];

int total[1003];

int main() {
	scanf("%d %d %d", &N, &M, &X);

	for (int e = 1; e <= M; e++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);

		adj[a].push_back(make_pair(t, b));
		adjR[b].push_back(make_pair(t, a));
	}

	//
	
	for (int i = 1; i <= N; i++) toX[i] = INF;
	toX[X] = 0;

	shortest.push(make_pair(-toX[X], X));

	while (shortest.size() > 0) {
		pair<int, int> cur = shortest.top(); shortest.pop();
		if (out[cur.second]) continue;
		out[cur.second] = 1;

		vector<pair<int, int>>::iterator iter;
		for (iter = adj[cur.second].begin(); iter != adj[cur.second].end(); iter++) {
			if (!out[iter->second]) {
				if (toX[iter->second] > toX[cur.second] + iter->first) {
					toX[iter->second] = toX[cur.second] + iter->first;
					shortest.push(make_pair(-toX[iter->second], iter->second));
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		out[i] = 0;
		fromX[i] = INF;
	}
	fromX[X] = 0;

	shortest.push(make_pair(-fromX[X], X));

	while (shortest.size() > 0) {
		pair<int, int> cur = shortest.top(); shortest.pop();
		if (out[cur.second]) continue;
		out[cur.second] = 1;

		vector<pair<int, int>>::iterator iter;
		for (iter = adjR[cur.second].begin(); iter != adjR[cur.second].end(); iter++) {
			if (!out[iter->second]) {
				if (fromX[iter->second] > fromX[cur.second] + iter->first) {
					fromX[iter->second] = fromX[cur.second] + iter->first;
					shortest.push(make_pair(-fromX[iter->second], iter->second));
				}
			}
		}
	}

	//
	
	for (int i = 1; i <= N; i++) {
		total[i] = toX[i] + fromX[i];
	}

	int result = max_element(total + 1, total + 1 + N) - total;
	printf("%d", total[result]);

	return 0;
}
