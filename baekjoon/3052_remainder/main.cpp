#include <cstdio>
#include <algorithm>

using namespace std;

int values[10];

int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", values + i);
		values[i] %= 42;
	}
	sort(values, values + 10);
	printf("%d\n", (int) (unique(values, values + 10) - values));

	return 0;
}
