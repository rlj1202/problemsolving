#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int tabs[102];

int positives;
int negatives;

int main() {
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++) {
		scanf("%d", tabs + n);
		if (tabs[n] > 0) positives++;
		else negatives++;
	}

	int result = 0;

	for (int b = 0; b < K; b++) {
		int pos = 0;
		int neg = 0;
		for (int n = b; n < N; n += K) {
			if (tabs[n] > 0) pos++;
			else neg++;
		}

		result = max(result, abs((positives - pos) - (negatives - neg)));
	}

	printf("%d\n", result);

	return 0;
}
