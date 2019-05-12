#include <iostream>
#include <cstring>

using namespace std;

int N;
int days[102][3];

int curScore[3];
int curHighest;
bool onBoard[3];

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		int day;
		char name[10];
		int delta;
		scanf("%d %s %d", &day, name, &delta);

		int cow = 0;
		if (strcmp("Mildred", name) == 0) cow = 0;
		else if (strcmp("Elsie", name) == 0) cow = 1;
		else if (strcmp("Bessie", name) == 0) cow = 2;
		days[day][cow] = delta;
	}

	int cnt = 0;
	for (int cow = 0; cow < 3; cow++) onBoard[cow] = 1;

	for (int day = 1; day <= 100; day++) {
		curHighest = -2000000009;
		for (int cow = 0; cow < 3; cow++) {
			curScore[cow] += days[day][cow];
			if (curHighest < curScore[cow]) curHighest = curScore[cow];
		}

		bool updated = false;

		for (int cow = 0; cow < 3; cow++) {
			if (curScore[cow] >= curHighest) {
				if (onBoard[cow] == 0) {
					onBoard[cow] = 1;
					updated = true;
				}
			} else {
				if (onBoard[cow] == 1) {
					onBoard[cow] = 0;
					updated = true;
				}
			}
		}

		if (updated) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
