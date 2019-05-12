#include <iostream>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int N, M;
int input[12][12]; // map[row][col] = zero for empty, minus one for filled

map<int, int> gd;

int grundy(int state) {
	if (state == 0) {
		return 0;
	} else if (gd.find(state) == gd.end()) {
		set<int> s;

		for (int col = 0; col < M; col++) {
			if (((state >> col*2) & 3) > 0) {
				s.insert(grundy(state - (1 << col*2)));
			}
		}
		for (int col = 0; col < M - 1; col++) {
			if (((state >> col*2) & 0xF) == 0xA) {
				s.insert(grundy(state - (0xA << col*2)));
			}
		}

		int number = 0;
		while (s.count(number)) number++;

		gd[state] = number;
	}

	return gd[state];
}

int main() {
	int times = 3;
	while (times--) {
		memset(input, -1, sizeof(input));
		scanf("%d %d", &N, &M);

		for (int n = 1; n <= N; n++) {
			char str[12];
			scanf("%s", str);

			for (int m = 1; m <= M; m++) {
				char c = str[m-1];

				if (c == '.') input[n][m] = 0;
				else if (c == '#') input[n][m] = -1;
			}
		}

		int flag = 0;
		for (int row = 1; row <= (N + 1) / 2; row++) {
			int state = 0;

			for (int col = 1; col <= M; col++) {
				int empties = 0;
				if (input[row*2-1][col] == 0) empties++;
				if (input[row*2][col] == 0) empties++;
				state = (state << 2) + empties;
			}

			flag ^= grundy(state);
		}

		if (flag == 0) printf("M\n");
		else printf("Y\n");
	}

	return 0;
}
