#include <iostream>

int N, K;
int queue[100005];
int front, rear;
bool out[100005];
int mintime[100005];

int main() {
	scanf("%d %d", &N, &K);

	queue[rear++] = N;
	out[N] = true;

	while (rear - front > 0) {
		int cur = queue[front++];

		int l = cur - 1;
		int r = cur + 1;
		int jump = cur * 2;

		if (0 <= l && l <= 100000 && !out[l]) {
			out[l] = true;
			mintime[l] = mintime[cur] + 1;
			queue[rear++] = l;
		}
		if (0 <= r && r <= 100000 && !out[r]) {
			out[r] = true;
			mintime[r] = mintime[cur] + 1;
			queue[rear++] = r;
		}
		if (0 <= jump && jump <= 100000 && !out[jump]) {
			out[jump] = true;
			mintime[jump] = mintime[cur] + 1;
			queue[rear++] = jump;
		}
	}

	printf("%d\n", mintime[K]);

	return 0;
}
