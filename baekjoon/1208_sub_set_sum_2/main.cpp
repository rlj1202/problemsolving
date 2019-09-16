#include <iostream>
#include <algorithm>

using namespace std;

int A[22];
int asize;

int B[22];
int bsize;

int P[2000006];
int psize;

int Q[2000006];
int qsize;

int main() {
	int N, S;
	scanf("%d %d", &N, &S);

	int asize = N / 2;
	int bsize = N - asize;

	for (int n = 0; n < asize; n++) scanf("%d", A + n);
	for (int n = 0; n < bsize; n++) scanf("%d", B + n);

	psize = 1 << asize;
	for (int i = 0; i < asize; i++) {
		int step = 1 << (i + 1);
		int len = step / 2;

		for (int j = 1; j < psize; j += step) {
			for (int k = 0; k < len; k++) {
				P[j + k] += A[i];
			}
		}
	}
	qsize = 1 << bsize;
	for (int i = 0; i < bsize; i++) {
		int step = 1 << (i + 1);
		int len = step / 2;

		for (int j = 1; j < qsize; j += step) {
			for (int k = 0; k < len; k++) {
				Q[j + k] += B[i];
			}
		}
	}

	sort(Q + 1, Q + qsize);

	long long count = 0;

	for (int i = 1; i < psize; i++) {
		int cur = P[i];

		if (cur == S) count++;

		int l = lower_bound(Q + 1, Q + qsize, S - cur) - Q;
		int r = upper_bound(Q + 1, Q + qsize, S - cur) - Q;

		count += r - l;
	}
	for (int i = 1; i < qsize; i++) {
		int cur = Q[i];

		if (cur == S) count++;
	}

	printf("%lld\n", count);

	return 0;
}
