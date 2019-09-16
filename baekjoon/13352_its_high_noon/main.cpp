#include <cstdio>

struct Vector {
	long long x, y;
};

Vector points[100005];

int main() {
	// read input
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		points[n] = {x, y};
	}


	// print result
	printf("%s\n", true ? "success" : "failure");

	return 0;
}
