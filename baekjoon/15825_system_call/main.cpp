#include <cstdio>
#include <cmath>

const long long INF = 0x3f3f3f3f3f3f3f3f;

long long accum[500005];

int nominations[2003];
int nomslen;

int main() {
	int N;
	scanf("%d", &N);
	for (int f = 0; f < N; f++) {
		int F;
		scanf("%d", &F);

		int maxbuffer = floor(sqrt(F));

		nomslen = 0;

		for (int i = 1; i <= maxbuffer; i++) {
			nominations[nomslen++] = i;
		}
		if (maxbuffer * maxbuffer != F) {
			nominations[nomslen++] = ceil((double) F / maxbuffer);
		}
		for (int i = maxbuffer - 1; i >= 1; i--) {
			nominations[nomslen++] = ceil((double) F / i);
		}
		nominations[nomslen] = 0;

		for (int i = 0; i < nomslen; i++) {
			int curbuffer = nominations[i];
			int prevbuffer = nominations[i + 1];

			int partitions = ceil((double) F / curbuffer);

			accum[curbuffer] += partitions;
			accum[prevbuffer] -= partitions;
		}
	}
	int T;
	scanf("%d", &T);

	long long mincost = INF;
	int minbuffer;

	long long partitions = 0;
	for (int b = 1; b <= 500000; b++) {
		partitions += accum[b];

		long long cost = (T + b) * partitions;

		if (mincost > cost) {
			mincost = cost;
			minbuffer = b;
		}
	}

	printf("%lld %d\n", mincost, minbuffer);

	return 0;
}
