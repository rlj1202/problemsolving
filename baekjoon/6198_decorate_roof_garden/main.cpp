#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Node { int height, index; };

int N;
int heights[80004];

Node stack[80004];
int stacksize;

int nextbuilding[80004];

long long result;

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", heights + n);
	}

	memset(nextbuilding, -1, sizeof(nextbuilding));
	for (int n = 0; n < N; n++) {
		Node cur = {heights[n], n};
		
		while (stacksize > 0 && stack[stacksize - 1].height <= cur.height) {
			Node pop = stack[--stacksize];
			nextbuilding[pop.index] = cur.index;
		}

		stack[stacksize++] = cur;
	}

	for (int n = 0; n < N; n++) {
		int cur = nextbuilding[n];
		if (cur == -1) cur = N;
		
		result += cur - n - 1;
	}

	printf("%lld\n", result);

	return 0;
}
