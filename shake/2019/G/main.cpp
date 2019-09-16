#include <cstdio>
#include <algorithm>

using namespace std;

long long cities[250005];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%lld", cities + n);
	}
	sort(cities, cities + N);

	int maxlevel = 0;
	long long mincity = 0x3f3f3f3f3f3f3f3f;
	long long maxcity = 0;

	for (int n = 0; n < N; n++) {
		long long cur = cities[n];

		int level = 0;
		long long temp = cur;
		while (temp) {
			level++;
			temp >>= 1;
		}

		if (maxlevel < level) {
			maxlevel = level;
			mincity = 0x3f3f3f3f3f3f3f3f;
			maxcity = 0;
		}
		if (maxlevel == level) {
			mincity = min(mincity, cur);
			maxcity = max(maxcity, cur);
		}
	}



	printf("%lld\n", 0LL);

	return 0;
}
