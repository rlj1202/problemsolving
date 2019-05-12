#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int set[50];

int main() {
	scanf("%d %d", &N, &S);
	for (int n = 0; n < N; n++) {
		scanf("%d", set + n);
	}
	sort(set, set + N);

	/* XXX */ for (int n = 0; n < N; n++) printf("%d ", set[n]); printf("\n");


	return 0;
}
