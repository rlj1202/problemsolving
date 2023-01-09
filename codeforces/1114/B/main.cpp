#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
pair<int, int> arr[200005];

int partitions[200005];

struct IndexCompare {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
		return a.second < b.second;
	}
};

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int n = 1; n <= N; n++) {
		int value;
		scanf("%d", &value);
		arr[n] = {value, n};
	}
	sort(arr + 1, arr + 1 + N, greater<pair<int, int>>());
	sort(arr + 1, arr + 1 + M*K, IndexCompare());

	long long sum = 0;

	for (int k = 0; k < K; k++) {
		for (int m = 0; m < M; m++) {
			sum += arr[1 + k*M + m].first;
		}
		partitions[k] = arr[k*M + M].second;
	}

	printf("%lld\n", sum);
	for (int k = 0; k < K - 1; k++) printf("%d ", partitions[k]); printf("\n");

	return 0;
}
