#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

char raw[500005];
char stack[500005];
int stackSize;

int levels[100005];
int levelSize;

int pairs;

int main() {
	scanf("%d", &N);

	for (int n = 0; n < N; n++) {
		scanf("%s", raw);

		int len = strlen(raw);
		stackSize = 0;
		for (int i = 0; i < len; i++) {
			char cur = raw[i];
			stack[stackSize++] = cur;
			
			if (stackSize >= 2 && stack[stackSize - 1] == ')' && stack[stackSize - 2] == '(') {
				stackSize -= 2;
			}
		}
		int sum = 0;
		for (int s = 0; s < stackSize; s++) {
			sum += stack[s] == '(' ? -1 : 1;
		}

		if (abs(sum) == stackSize) {
			levels[levelSize++] = sum;
		}
	}
	sort(levels, levels + levelSize);

	int l = 0;
	int r = levelSize - 1;
	while (l < r) {
		int left = abs(levels[l]);
		int right = abs(levels[r]);
		if (left == right && levels[l] + levels[r] == 0) {
			pairs++;
			l++;
			r--;
		} else {
			if (left < right) {
				r--;
			} else {
				l++;
			}
		}
	}

	printf("%d\n", pairs);

	return 0;
}
