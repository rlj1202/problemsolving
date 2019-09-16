#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int burgur = 0x3f3f3f3f;
	int beverage = 0x3f3f3f3f;
	for (int i = 0; i < 3; i++) {
		int price;
		scanf("%d", &price);
		burgur = min(burgur, price);
	}
	for (int i = 0; i < 2; i++) {
		int price;
		scanf("%d", &price);
		beverage = min(beverage, price);
	}
	printf("%d\n", burgur + beverage - 50);

	return 0;
}
