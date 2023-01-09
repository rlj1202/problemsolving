#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N, D, E;
	scanf("%d %d %d", &N, &D, &E);
	
	int best = 0x3f3f3f3f;

	int maxeuros = N / (E * 5);

	for (int euros = 0; euros <= maxeuros; euros++) {
		int value = N - euros * E * 5;

		int dollars = value / D;
		value -= dollars * D;

		best = min(best, value);
	}
	
	printf("%d\n", best);

	return 0;
}
