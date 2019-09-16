#include <cstdio>

int docs[102];

int q[10004];
int indices[10004];
int front, rear;
int order;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		front = rear = 0;
		order = 0;

		int N, M;
		scanf("%d %d", &N, &M);
		for (int n = 0; n < N; n++) {
			scanf("%d", docs + n);
			q[rear] = docs[n];
			indices[rear++] = n;
		}

		while (rear - front) {
			int cur = q[front];
			int pos = indices[front++];
			bool printable = true;

			for (int i = front; i < rear; i++) {
				if (q[i] > cur) {
					printable = false;
					break;
				}
			}

			if (printable) {
				order++;
				if (pos == M) {
					break;
				}
			} else {
				q[rear] = cur;
				indices[rear++] = pos;
			}
		}

		printf("%d\n", order);
	}
	
	return 0;
}
