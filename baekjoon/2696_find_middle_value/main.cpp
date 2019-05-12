#include <cstdio>
#include <queue>

using namespace std;

int T;

int N;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		priority_queue<int> maxheap;
		priority_queue<int, vector<int>, greater<int>> minheap;

		int answer[5003];
		int answerlen = 0;

		for (int n = 0; n < N; n++) {
			int value;
			scanf("%d", &value);

			if (!maxheap.empty() && maxheap.top() > value) maxheap.push(value);
			else minheap.push(value);

			if (maxheap.size() < minheap.size()) {
				maxheap.push(minheap.top());
				minheap.pop();
			}
			if (maxheap.size() - minheap.size() > 1) {
				minheap.push(maxheap.top());
				maxheap.pop();
			}

			if (n % 2 == 0) {
				answer[answerlen++] = maxheap.top();
			}
		}

		printf("%d\n", answerlen);
		for (int i = 0; i < answerlen; i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}

	return 0;
}
