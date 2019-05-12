#include <iostream>

int X, Y, Z;

int main() {
	scanf("%d %d %d", &X, &Y, &Z);

	float result = Z * ((float) Y / X);

	printf("%.2f\n", result);

	return 0;
}
