#include <cstdio>
#include <cstring>

using namespace std;

int dvdpos[100005]; // dvdpos[dvdid] = position

int tree[800005]; // sum tree

void update(int i, int delta) {
	while (i <= 200000) {
		tree[i] += delta;
		i += i & -i;
	}
}

int accum(int i) {
	int result = 0;
	while (i > 0) {
		result += tree[i];
		i -= i & -i;
	}
	return result;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// read input
		int N, M;
		scanf("%d %d", &N, &M);

		// initiate dvd positions
		memset(tree, 0, sizeof(tree));
		for (int n = 1; n <= N; n++) {
			dvdpos[n] = N - n + 1;
			update(dvdpos[n], 1);
		}

		int lastpos = N;

		for (int m = 0; m < M; m++) {
			int dvdid;
			scanf("%d", &dvdid);

			int result = accum(lastpos) - accum(dvdpos[dvdid]);
			// print result
			printf("%d ", result);

			update(dvdpos[dvdid], -1);
			if (result) lastpos++;
			update(lastpos, 1);
			dvdpos[dvdid] = lastpos;
		}
		printf("\n");
	}
	
	return 0;
}
