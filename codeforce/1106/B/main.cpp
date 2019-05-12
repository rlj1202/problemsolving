#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int dishes[100005];
int costs[100005];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		scanf("%d", dishes + n);
	}
	for (int n = 1; n <= N; n++) {
		scanf("%d", costs + n);
		q.push(make_pair(costs[n], n));
	}
	for (int m = 0; m < M; m++) {
		long long total = 0;

		int food, count;
		scanf("%d %d", &food, &count);

		while (count) {
			if (dishes[food] > 0) {
				long long discount = min(count, dishes[food]);

				dishes[food] -= discount;
				count -= discount;

				total += costs[food] * discount;
			} else {
				if (q.size() == 0) break;

				pair<int, int> cheapest = q.top();
				if (dishes[cheapest.second] == 0) {
					q.pop();
					continue;
				}

				long long discount = min(dishes[cheapest.second], count);

				dishes[cheapest.second] -= discount;
				count -= discount;

				total += costs[cheapest.second] * discount;
			}
		}

		if (count) total = 0;

		printf("%lld\n", total);
	}

	return 0;
}
