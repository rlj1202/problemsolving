#include <iostream>
#include <cstring>

using namespace std;

int T;

char str[202];

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%s", str);

		int state = 1;
		char *pos = str;
		while (*pos != 0) {
			switch (state) {
				case 1:
					if (strncmp(pos, "100", 3) == 0) {
						state = 2;
						pos += 3;
					} else if (strncmp(pos, "01", 2) == 0) {
						state = 4;
						pos += 2;
					} else {
						state = 5;
					}

					break;
				case 2:
					if (*pos == '0') {
						pos++;
					} else if (*pos == '1') {
						state = 3;
						pos++;
					}

					break;
				case 3:
					if (strncmp(pos, "100", 3) == 0) {
						state = 1;
					} else if (strncmp(pos, "01", 2) == 0) {
						state = 1;
					} else if (*pos == '1') {
						pos++;
					} else {
						state = 5;
					}

					break;
				case 4:
					state = 1;

					break;
				case 5:
					pos++;

					break;
				default:
					break;
			}
		}
		
		if (state == 3 || state == 4) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
