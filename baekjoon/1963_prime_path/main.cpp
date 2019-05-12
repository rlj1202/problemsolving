#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int T;

int primes[2003];
int plen;

int leftbound;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int visited[2003];
int minpath[2003];

int dijkstra(int ifrom, int ito) {
	memset(visited, 0, sizeof(visited));
	memset(minpath, 0x3f, sizeof(minpath));

	q.push({0, ifrom});
	minpath[ifrom] = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.top(); q.pop();
		if (visited[cur.second]) continue;
		visited[cur.second] = 1;

		int digit = primes[cur.second];
		int digitpos = 1;
		for (int i = 0; i < 4; i++) {
			int base = primes[cur.second] - (digit % 10) * digitpos;

			for (int d = 0; d <= 9; d++) {
				int next = base + d * digitpos;
				if (next == primes[cur.second]) continue;

				int index = lower_bound(primes + leftbound, primes + plen, next) - primes;
				if (primes[index] == next) {
					minpath[index] = min(minpath[index], cur.first + 1);

					if (!visited[index]) q.push({minpath[index], index});
				}
			}

			digit /= 10;
			digitpos *= 10;
		}
	}

	return minpath[ito];
}

int main() {
	// make prime numbers
	primes[plen++] = 2;
	for (int n = 3; n < 10000; n++) {
		bool isprime = true;
		int bound = sqrt(n);
		for (int pi = 0; pi < plen && primes[pi] <= bound; pi++) {
			if (n % primes[pi] == 0) {
				isprime = false; break;
			}
		}
		if (isprime) primes[plen++] = n;
	}

	leftbound = lower_bound(primes, primes + plen, 1000) - primes;

	// read input
	scanf("%d", &T);

	while (T--) {
		memset(visited, 0, sizeof(visited));

		int from, to;
		scanf("%d %d", &from, &to);

		int ifrom = lower_bound(primes + leftbound, primes + plen, from) - primes;
		int ito = lower_bound(primes + leftbound, primes + plen, to) - primes;

		int result = dijkstra(ifrom, ito);

		printf("%d\n", result);
	}

	return 0;
}
