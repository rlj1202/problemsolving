#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
long long dormitories[200005]; // sum

int main() {
	// read input
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) { // dormitories
		long long dormitory;
		scanf("%lld", &dormitory);

		dormitories[n] = dormitories[n - 1] + dormitory;
	}

	for (int m = 1; m <= M; m++) { // letters
		long long room;
		scanf("%lld", &room);

		int dormitory = lower_bound(dormitories + 1, dormitories + 1 + N, room) - dormitories - 1;
		room -= dormitories[dormitory];

		// print result
		printf("%d %lld\n", dormitory + 1, room);
	}

	return 0;
}
