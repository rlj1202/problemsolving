#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int N;
int gd[1003];

int mex(int *set) {
	int number = 0;

	if (set[0] == number) number++;
	if (set[2] == number) number++;
	if (set[3] == number) number++;

	return number;
}

int grundy(int n) {
	if (n == 0) return 0;
	else if (gd[n] == -1) {
		set<int> s;
		if (n - 4 >= 0) s.insert(grundy(n - 4));
		if (n - 3 >= 0) s.insert(grundy(n - 3));
		if (n - 1 >= 0) s.insert(grundy(n - 1));

		int number = 0;
		while (s.count(number)) number++;

		gd[n] = number;
	}

	return gd[n];
}

int main() {
	scanf("%d", &N);
	memset(gd, -1, sizeof(gd));

	grundy(N);

	if (gd[N] == 0) printf("CY");
	else printf("SK");

	return 0;
}
