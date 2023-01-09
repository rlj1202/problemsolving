#include <iostream>
#include <cstring>

using namespace std;

char str[1003];
int len;

int main() {
	scanf("%s", str);
	len = strlen(str);

	int v = 0;
	int h = 0;

	for (int i = 0; i < len; i++) {
		char cur = str[i] - '0';

		if (cur == 0) { // vert
			if (v == 0) {
				v = 1;
				printf("%d %d\n", 3, 4);
			} else {
				v = 0;
				printf("%d %d\n", 1, 4);
			}
		} else { // horz
			if (h == 0) {
				h = 1;
				printf("%d %d\n", 1, 1);
			} else {
				h = 0;
				printf("%d %d\n", 1, 3);
			}
		}
	}
	
	return 0;
}
