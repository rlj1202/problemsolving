#include <iostream>
#include <cstring>

using namespace std;

int N;

int main() {
	scanf("%d", &N);

	int mid = N / 2;
	int l = 1;
	int r = N - 1;

	while (l <= mid) {
		bool flags[10];
		memset(flags, 0, sizeof(flags));

		bool valid = true;

		int tmp;

		tmp = l;
		while (tmp > 0) {
			int digit = tmp % 10;
			if (flags[digit]) {
				valid = false;
				break;
			}

			flags[digit] = 1;
			tmp /= 10;
		}

		if (!valid) {
			l++;
			r--;
			continue;
		}

		tmp = r;
		while (tmp > 0) {
			int digit = tmp % 10;
			if (flags[digit]) {
				valid = false;
				break;
			}

			flags[digit] = 1;
			tmp /= 10;
		}

		if (valid) {
			printf("%d + %d\n", l, r);
			return 0;
		}

		l++;
		r--;
	}

	printf("%d\n", -1);

	return 0;
}
