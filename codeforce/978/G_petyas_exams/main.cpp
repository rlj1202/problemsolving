#include <iostream>
#include <algorithm>

using namespace std;

struct Exam {
	int id;
	int s, d, c;
};

bool operator< (const Exam &a, const Exam &b) {
	return a.d < b.d;
}

int N, M;
Exam exams[102];

int result[102];

int main() {
	// read input
	scanf("%d %d", &N, &M);

	for (int m = 1; m <= M; m++) {
		int s, d, c;
		scanf("%d %d %d", &s, &d, &c);

		exams[m] = {m, s, d, c};
		result[d] = M + 1;
	}

	//
	sort(exams + 1, exams + 1 + M); // sort by deadline

	for (int n = 1; n <= N; n++) {
		if (result[n] == M + 1) continue;

		for (int m = 1; m <= M; m++) {
			Exam &cur = exams[m];

			if (n >= cur.s && cur.c > 0 && n < cur.d) {
				result[n] = cur.id;
				cur.c--;
				break;
			}
		}
	}

	// check invalidity
	for (int m = 1; m <= M; m++) {
		Exam cur = exams[m];
		if (cur.c > 0) {
			printf("%d\n", -1);
			return 0;
		}
	}

	// print result
	for (int n = 1; n <= N; n++) {
		printf("%d ", result[n]);
	}
	printf("\n");

	return 0;
}
