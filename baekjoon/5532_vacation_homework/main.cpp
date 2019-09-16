#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int L, A, B, C, D;
	scanf("%d %d %d %d %d", &L, &A, &B, &C, &D);

	printf("%d\n", L - max((int) ceil(A / (float) C), (int) ceil(B / (float) D)));

	return 0;
}
