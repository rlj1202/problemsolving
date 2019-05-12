#include <iostream>
#include <algorithm>

using namespace std;

struct Cow { int t, d; int index; };

int N;
Cow cows[100005];

bool operator< (const Cow &a, const Cow &b) {
	if (a.t * 2 * b.d < b.t * 2 * a.d) return true;
	else return false;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int t, d;
		scanf("%d %d", &t, &d);
		cows[n] = {t, d, n + 1};
	}
	sort(cows, cows + N);

	long long result = 0;

	long long time_passed = 0;
	for (int n = 0; n < N; n++) {
		result += time_passed * cows[n].d;
		time_passed += cows[n].t * 2;
	}

	printf("%lld\n", result);

	return 0;
}
