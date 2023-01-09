#include <iostream>
#include <vector>

using namespace std;

int N;
int nums[200005];
vector<int> adj[200005];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		scanf("%d", nums + n);
	}

	for (int n = 0; n < N - 1; n++) {
		int x, y;
		scanf("%d %d", &x, &y);

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	return 0;
}
