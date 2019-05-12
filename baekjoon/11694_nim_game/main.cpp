#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int N;
int flag;
int excep;

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		int value;
		scanf("%d", &value);
		flag ^= value;
		excep |= value;
	}

	if (excep == 1) {
		if (N % 2 == 0) printf("koosaga");
		else printf("cubelover");
	} else {
		if (flag != 0) printf("koosaga");
		else printf("cubelover");
	}

	return 0;
}
