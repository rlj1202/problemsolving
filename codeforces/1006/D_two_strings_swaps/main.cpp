#include <iostream>
#include <algorithm>

using namespace std;

int len;
char a[100005];
char b[100005];

int main() {
	scanf("%d", &len);
	scanf("%s %s", a, b);

	int cnt = 0;

	for (int n = 0; n < len / 2; n++) {
		char tmp[4];

		tmp[0] = a[n];
		tmp[1] = a[len - n - 1];
		tmp[2] = b[n];
		tmp[3] = b[len - n - 1];

		if (tmp[2] == tmp[3]) {
			if (tmp[0] != tmp[1]) cnt++;
		} else {
			for (int i = 2; i <= 3; i++) {
				bool found = false;
				for (int j = 0; j < 4; j++) {
					if (i == j) continue;
					if (tmp[i] == tmp[j]) found = true;
				}
				if (!found) cnt++;
			}
		}
	}

	if (len % 2 == 1) {
		if (a[len / 2] != b[len / 2]) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
