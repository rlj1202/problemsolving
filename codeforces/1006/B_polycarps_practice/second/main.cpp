#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
pair<int, int> arr[2003];

int main() {
	scanf("%d %d", &N, &K);

	for (int n = 0; n < N; n++) {
		int value;
		scanf("%d", &value);

		arr[n] = make_pair(value, n);
	}

	sort(arr, arr + N);

	int total = 0;
	int indices[2003] = {0, };
	for (int i = 0; i < K; i++) {
		pair<int, int> cur = arr[N - i - 1];
		total += cur.first;
		indices[i + 1] = cur.second + 1;
	}
	printf("%d\n", total);

	sort(indices+1, indices+1 + K);
	indices[K] = N;

	for (int i = 1; i <= K; i++) {
		printf("%d ", indices[i] - indices[i - 1]);
	}
	printf("\n");

	return 0;
}
