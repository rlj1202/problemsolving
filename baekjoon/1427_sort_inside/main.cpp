#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[11];

int main() {
	scanf("%s", str);
	int len = strlen(str);
	sort(str, str + len, [] (int a, int b) { return a > b; });
	printf("%s\n", str);

	return 0;
}
