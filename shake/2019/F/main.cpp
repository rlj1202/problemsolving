#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

long long smallcandies[250005];
long long smallcandiessum[250005];
int smallcandieslen;
long long bigcandies[250005];
long long bigcandiessum[250005];
int bigcandieslen;

int main() {
	int N, W;
	scanf("%d %d", &N, &W);
	
	for (int n = 0; n < N; n++) {
		int weight, sweet;
		scanf("%d %d", &weight, &sweet);
		if (weight == 3) {
			smallcandies[++smallcandieslen] = sweet;
		} else {
			bigcandies[++bigcandieslen] = sweet;
		}
	}

	sort(smallcandies + 1, smallcandies + smallcandieslen + 1, greater<long long>());
	sort(bigcandies + 1, bigcandies + bigcandieslen + 1, greater<long long>());

	for (int i = 1; i <= smallcandieslen; i++) {
		smallcandiessum[i] = smallcandiessum[i - 1] + smallcandies[i];
	}
	for (int i = 1; i <= bigcandieslen; i++) {
		bigcandiessum[i] = bigcandiessum[i - 1] + bigcandies[i];
	}

	long long result = 0;

	for (int i = 0; i <= smallcandieslen; i++) {
		int smallweight = i * 3;
		int j = (W - smallweight) / 5;
		j = min(j, bigcandieslen);
		j = max(j, 0);

		int bigweight = j * 5;

		int totalweight = smallweight + bigweight;
		if (totalweight > W) continue;

		long long totalsweet = smallcandiessum[i] + bigcandiessum[j];
		result = max(result, totalsweet);
	}

	printf("%lld\n", result);

	return 0;
}
