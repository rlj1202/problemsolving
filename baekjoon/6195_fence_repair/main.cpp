#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> planks;

long long result;

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int value;
		scanf("%d", &value);
		planks.push(value);
	}

	while (planks.size() > 1) {
		int a = planks.top(); planks.pop();
		int b = planks.top(); planks.pop();

		result += a + b;
		planks.push(a + b);
	}

	printf("%lld\n", result);

	return 0;
}
