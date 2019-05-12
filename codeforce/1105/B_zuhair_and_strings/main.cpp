#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
char str[200005];

int levels[26];

int main() {
	scanf("%d %d", &N, &K);
	scanf("%s", str);

	char last = str[0];
	int count = 0;

	for (int n = 0; n <= N; n++) {
		char cur = str[n];

		if (last == cur) {
			count++;
		} else {
			levels[last - 'a'] += count / K;

			last = cur;
			count = 1;
		}
	}

	int index = max_element(levels, levels + 26) - levels;

	printf("%d\n", levels[index]);

	return 0;
}
