#include <iostream>
#include <cstring>

using namespace std;

int N;
char str[200005];

int main() {
	scanf("%d", &N);
	scanf("%s", str);

	int len = strlen(str);
	int remove = len - 1;

	for (int i = 0; i < len; i++) {
		if (str[i] > str[i + 1]) {
			remove = i;
			break;
		}
	}

	str[remove] = 0;
	printf("%s", str);
	printf("%s\n", str + remove + 1);

	return 0;
}
