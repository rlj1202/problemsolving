#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
char str[200005];

int main() {
	scanf("%d %s", &N, str + 1);

	int cnt = 0;

	for (int i = 2; i <= N; i++) {
		if (str[i - 1] == str[i]) {
			for (int d = 0; d < 3; d++) {
				char cur = "RGB"[d];
				if (cur != str[i - 1] && cur != str[i + 1]) {
					cnt++;
					str[i] = cur;
					break;
				}
			}
		}
	}

	printf("%d\n", cnt);
	printf("%s\n", str + 1);

	return 0;
}
