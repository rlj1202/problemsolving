#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int N, M;
int gd[102][102];

int grundy(int n, int m) {
	if (n == 1 && m == 1) {
		return 0;
	} else if (gd[n][m] == -1) {
		set<int> s;

		for (int stone = 1; stone < n; stone++) s.insert(grundy(stone, n - stone));
		for (int stone = 1; stone < m; stone++) s.insert(grundy(stone, m - stone));
		
		int number = 0;
		while(s.count(number)) number++;

		gd[n][m] = number;
	}

	return gd[n][m];
}

int main() {
	scanf("%d %d", &N, &M);
	memset(gd, -1, sizeof(gd));

	grundy(N, M);

	if (gd[N][M] == 0) printf("B");
	else printf("A");

	return 0;
}
