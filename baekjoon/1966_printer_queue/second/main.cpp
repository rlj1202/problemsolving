#include <iostream>
#include <queue>

using namespace std;

int T;

int N, M;
int docs[10004];
int indices[10004];
int front, rear;

priority_queue<int> maxheap;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &M);
		
		front = 0;
		rear = N;

		priority_queue<int> empty;
		swap(maxheap, empty);

		for (int n = 0; n < N; n++) {
			scanf("%d", docs + n);
			indices[n] = n;
			maxheap.push(docs[n]);
		}

		int count = 0;

		while (rear - front > 0) {
			int cur = docs[front];
			int index = indices[front];
			front++;

			if (cur != maxheap.top()) {
				docs[rear] = cur;
				indices[rear] = index;
				rear++;
			} else {
				maxheap.pop();
				count++;

				if (index == M) {
					break;
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}
