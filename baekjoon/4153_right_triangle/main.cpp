#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	while (true) {
		int lens[3];
		for (int i = 0; i < 3; i++) scanf("%d", lens + i);
		if (lens[0] == 0 && lens[1] == 0 && lens[2] == 0) break;
		sort(lens, lens + 3);
		for (int i = 0; i < 3; i++) lens[i] = lens[i] * lens[i];

		printf("%s\n", lens[2] == lens[0] + lens[1] ? "right" : "wrong");
	}

	return 0;
}
