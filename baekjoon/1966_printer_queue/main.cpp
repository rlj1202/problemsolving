#include <iostream>
#include <algorithm>

using namespace std;

struct Document { int priority; int index; };

bool operator< (const Document &a, const Document &b) {
	if (a.index == 0x3f3f3f3f) return true;
	if (b.index == 0x3f3f3f3f) return false;;

	if (a.priority != b.priority) return a.priority < b.priority;
	else return a.index > b.index;
}

int T;

int N, M;
Document arr[5][102];
int height;

void remove(int index) {
	arr[0][index] = {0, 0x3f3f3f3f};

	for (int l = 1; l <= height; l++) {
		int len = 1 << l;
		int prev = 1 << (l - 1);

		for (int n = max(0, index - len + 1); n < N - len + 1; n++)
			arr[l][n] = max(arr[l - 1][n], arr[l - 1][n + prev]);
	}
}

Document query(int l, int r) {
	int tmp = r - l + 1;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;
	int len = 1 << log;

	return max(arr[log][l], arr[log][r - len + 1]);
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &M);

		for (int n = 0; n < N; n++) {
			int value;
			scanf("%d", &value);
			arr[0][n] = {value, n};
		}

		int tmp = N;
		height = 0;
		while ((tmp >>= 1) != 0) height++;

		for (int l = 1; l <= height; l++) {
			int len = 1 << l;
			int prev = 1 << (l - 1);

			for (int n = 0; n < N - len + 1; n++)
				arr[l][n] = max(arr[l - 1][n], arr[l - 1][n + prev]);
		}

		int pointer = 0;
		int count = 0;
		while (true) {
			Document cur = query(pointer, N - 1);
			count++;

			if (cur.index == M) break;

			remove(cur.index);
			pointer = cur.index + 1;
			if (pointer == N) pointer = 0;
		}

		printf("%d\n", count);
	}

	return 0;
}
