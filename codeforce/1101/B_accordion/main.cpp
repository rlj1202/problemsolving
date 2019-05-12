#include <iostream>
#include <cstring>

using namespace std;

char accordion[500005];
int len;

int main() {
	scanf("%s", accordion);
	len = strlen(accordion);

	int l = 0;
	int r = len - 1;

	int removes = 0;
	
	while (accordion[l] != '[' && l < len) {
		l++;
		removes++;
	}
	l++;
	while (accordion[l] != ':' && l < len) {
		l++;
		removes++;
	}

	while (accordion[r] != ']' && r >= 0) {
		r--;
		removes++;
	}
	r--;
	while (accordion[r] != ':' && r >= 0) {
		r--;
		removes++;
	}

	for (int i = l + 1; i <= r - 1; i++) {
		if (accordion[i] != '|') removes++;
	}

	if (l < r) {
		printf("%d\n", len - removes);
	} else {
		printf("%d\n", -1);
	}

	return 0;
}
