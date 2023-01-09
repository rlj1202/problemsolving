#include <iostream>
#include <cstring>

using namespace std;

char str[1003];
int len;

int rows[4];
int cols[4];

int main() {
	scanf("%s", str);
	len = strlen(str);

	for (int i = 0; i < len; i++) {
		char cur = str[i] - '0';

		int r = 0, c = 0;

		if (cur == 0) { // vertical
			for (int i = 0; i < 4; i++) {
				if (cols[i] <= 2) {
					r = cols[i];
					c = i;
					for (int j = cols[i]; j < 4; j++) {
						rows[j]++;
					}
					cols[i] += 2;
					break;
				}
			}
		} else { // horizontal
			for (int i = 0; i < 4; i++) {
				if (rows[i] <= 2) {
					r = i;
					c = rows[i];
					for (int j = rows[i]; j < 4; j++) {
						cols[j]++;
					}
					rows[i] += 2;
					break;
				}
			}
		}

		printf("%d %d\n", r + 1, c + 1);

		for (int i = 0; i < 4; i++) {
			if (cols[i] == 4) {
				cols[i] = 0;
				for (int j = 0; j < 4; j++) {
					rows[j]--;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			if (rows[i] == 4) {
				rows[i] = 0;
				for (int j = 0; j < 4; j++) {
					cols[j]--;
				}
			}
		}
	}

	return 0;
}
