#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100005];
int maxTable[20][100005];
int minTable[20][100005];

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++)
		scanf("%d", arr + n);

	int log = 31 - __builtin_clz(N); // XXX I do not prefer this.
	//int log = 0;
	//int tmp = N;
	//while ((tmp >>= 1) != 0) log++;

	//

	for (int n = 1; n <= N; n++) {
		maxTable[0][n] = arr[n];
		minTable[0][n] = arr[n];
	}

	for (int i = 1; i <= log; i++) {
		int len = 1 << (i - 1);

		for (int j = 1; j <= N; j++) {
			maxTable[i][j] = max(maxTable[i - 1][j], maxTable[i - 1][min(N, j + len)]);
			minTable[i][j] = min(minTable[i - 1][j], minTable[i - 1][min(N, j + len)]);
		}
	}

	//

	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int len = b - a + 1;
		
		int log = 31 - __builtin_clz(len); // XXX I do not prefer this.
		//int log = 0;
		//int tmp = len;
		//while ((tmp >>= 1) != 0) log++;

		int minResult = min(minTable[log][a], minTable[log][b - (1 << log) + 1]);
		int maxResult = max(maxTable[log][a], maxTable[log][b - (1 << log) + 1]);
		printf("%d %d\n", minResult, maxResult);
	}

	return 0;
}
