#include <cstdio>
#include <algorithm>

using namespace std;

struct Nation {
	int id, gold, silver, bronze;
	bool operator< (const Nation &o) const {
		if (gold != o.gold) return gold > o.gold;
		if (silver != o.silver) return silver > o.silver;
		return bronze > o.bronze;
	}
};

Nation nations[1003];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++) {
		scanf("%d %d %d %d",
				&nations[n].id, &nations[n].gold, &nations[n].silver, &nations[n].bronze);
	}
	sort(nations, nations + N);

	Nation prev = nations[0];
	int result = 0;
	for (int n = 0; n < N; n++) {
		if (prev < nations[n]) result = n;
		if (nations[n].id == K) {
			printf("%d\n", result + 1);
			break;
		}
		prev = nations[n];
	}

	return 0;
}
