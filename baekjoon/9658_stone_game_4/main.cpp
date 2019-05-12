#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int N;
int gd[1003];

int grundy(int n) {
	if (n == 1) return 0;
	else if (gd[n] == -1) {
		set<int> s;

		if (n - 4 >= 1) s.insert(grundy(n - 4));
		if (n - 3 >= 1) s.insert(grundy(n - 3));
		if (n - 1 >= 1) s.insert(grundy(n - 1));

		int number = 0;
		while (s.count(number)) number++;

		gd[n] = number;
	}

	return gd[n];
}

int main() {
	scanf("%d", &N);
	memset(gd, -1, sizeof(gd));

	if (grundy(N) == 0) printf("CY");
	else printf("SK");

	return 0;
}
