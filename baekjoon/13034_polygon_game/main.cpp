#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int N;
int gd[1003];

int grundy(int n) {
	if (n == 0 || n == 1) {
		return 0;
	} else if (gd[n] == -1) {
		set<int> s;
		for (int j = 0; j <= n - 2; j++) {
			s.insert(grundy(j) ^ grundy(n - 2 - j));
		}

		int number = 0;
		while (s.count(number)) number++;
		gd[n] = number;
	}

	return gd[n];
}

int main() {
	scanf("%d", &N);
	memset(gd, -1, sizeof(gd));

	if (grundy(N) == 0) printf("2");
	else printf("1");

	return 0;
}
