#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

long long sum;
int deltas[100005];

int main() {
	// read input
	scanf("%d %d", &N, &M);

	for (int n = 0; n < N; n++) {
		int a, b;
		scanf("%d %d", &a, &b);

		sum += a;
		deltas[n] = a - b;
	}
	sort(deltas, deltas + N);
	
	//
	int cnt = 0;
	while (sum > M && cnt < N) sum -= deltas[N - cnt++ - 1];

	// print result
	if (sum > M) cnt = -1;
	printf("%d\n", cnt);

	return 0;
}
