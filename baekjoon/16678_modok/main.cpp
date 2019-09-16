#include <cstdio>
#include <algorithm>

using namespace std;

long long honors[100005];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
		scanf("%lld", honors + n);
	sort(honors, honors + N);

	long long result = 0;

	int cur = 1;

	for (int n = 0; n < N; n++) {
		if (honors[n] == cur) {
			cur++;
		} else if (honors[n] > cur) {
			result += honors[n] - cur;
			cur++;
		}
	}
	
	printf("%lld\n", result);

	return 0;
}
