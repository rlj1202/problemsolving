#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int N;

int main() {
	scanf("%d", &N);

	int coins = INF;

	for (int five = 0; five <= N / 5; five++)
		if ((N - five * 5) % 2 == 0)
			coins = min(coins, five + (N - five * 5) / 2);

	if (coins != INF) printf("%d\n", coins);
	else printf("%d\n", -1);

	return 0;
}
