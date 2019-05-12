#include <iostream>

int cnt[4];

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d", cnt + i);
	}

	if (cnt[0] == cnt[3]) {
		if (cnt[0] == 0 && cnt[2] > 0) printf("%d\n", 0);
		else printf("%d\n", 1);
	} else {
		printf("%d\n", 0);
	}

	return 0;
}
