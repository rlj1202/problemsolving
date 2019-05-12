/*
 * 2018 안씨 겨울 코딩 캠프
 * 서현이 형 풀이
 */
#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
long long S;

int result[200005];
int len;

int main() {
	// read input
	scanf("%d %d %lld", &N, &K, &S);

	//
	long long remains = S;
	int cnt = K;
	long long pos = 1;
	bool fail = false;
	while (remains > 0 && cnt > 0) {
		cnt--;
		long long diff = min(remains - cnt, (long long) N - 1); // XXX

		if (diff <= 0) {
			fail = true;
			break;
		}

		if (pos + diff <= N) pos += diff;
		else if (pos - diff >= 1) pos -= diff;
		else {
			fail = true;
			break;
		}

		remains -= diff;
		result[len++] = pos;
	}

	if (remains != 0 || cnt != 0) {
		fail = true;
	}

	// print result
	printf("%s\n", fail ? "NO" : "YES");
	if (!fail) {
		for (int i = 0; i < len; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}

	return 0;
}
