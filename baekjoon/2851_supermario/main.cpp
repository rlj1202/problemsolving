#include <cstdio>
#include <algorithm>

using namespace std;

int result;
bool stop;

int main() {
	for (int i = 0; i < 10; i++) {
		int val;
		scanf("%d", &val);
		if (!stop && abs(100 - result) >= abs(100 - result - val)) result += val;
		else stop = true;
	}

	printf("%d\n", result);

	return 0;
}
