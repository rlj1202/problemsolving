#include <iostream>
#include <cstring>

using namespace std;

int M;
int set[21];

int main() {
	scanf("%d", &M);

	while (M--) {
		char cmd[7];
		int arg;
		scanf("%s", cmd);

		if (strcmp("add", cmd) == 0) {
			scanf("%d", &arg);
			set[arg] = 1;
		} else if (strcmp("remove", cmd) == 0) {
			scanf("%d", &arg);
			set[arg] = 0;
		} else if (strcmp("check", cmd) == 0) {
			scanf("%d", &arg);
			printf("%d\n", set[arg]);
		} else if (strcmp("toggle", cmd) == 0) {
			scanf("%d", &arg);
			set[arg] = !set[arg];
		} else if (strcmp("all", cmd) == 0) {
			for (int i = 1; i <= 20; i++)
				set[i] = 1;
		} else if (strcmp("empty", cmd) == 0) {
			for (int i = 1; i <= 20; i++)
				set[i] = 0;
		}
	}

	return 0;
}
