#include <iostream>

int N, K;
long long S;

int result[200005];
int len;

int main() {
	// read input
	scanf("%d %d %lld", &N, &K, &S);

	//
	int remains = S;
	int cnt = K;
	int pos = 1;
	bool fail = false;
	while (remains > 0 && cnt > 0) {
		int diff = remains / cnt;
		int remainder = remains % cnt;

		if (remainder != 0) {
			diff++;
		}

		if (pos + diff <= N) {
			pos += diff;
		} else if (pos - diff >= 1) {
			pos -= diff;
		} else {
			fail = true;
			break;
		}

		remains -= diff;
		cnt--;
		result[len++] = pos;
	}

	// print result
	printf("%s\n", !fail ? "YES" : "NO");
	if (!fail) {
		for (int i = 0; i < len; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
	}

	return 0;
}
