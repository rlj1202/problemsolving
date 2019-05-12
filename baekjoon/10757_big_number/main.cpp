#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char str[10004];

int A[10004];
int B[10004];
int C[10004];
int lenA;
int lenB;
int lenC;

void read(int *arr, int *len) {
	scanf("%s", str);
	*len = strlen(str);

	for (int i = 0; i < *len; i++) {
		arr[*len - i - 1] = str[i] - '0';
	}
}

int main() {
	read(A, &lenA);
	read(B, &lenB);

	lenC = max(lenA, lenB);
	for (int i = 0; i < lenC; i++) {
		C[i] = A[i] + B[i];
	}

	for (int i = 0; i < lenC; i++) {
		int remainder = C[i] % 10;
		int carry = C[i] / 10;
		C[i] = remainder;
		C[i + 1] += carry;
	}
	if (C[lenC] != 0) lenC++;
	
	int carry;
	while ((carry = C[lenC - 1] / 10)) {
		int remainder = C[lenC - 1] % 10;
		C[lenC - 1] = remainder;
		C[lenC++] = carry;
	}

	for (int i = 0; i < lenC; i++) {
		printf("%d", C[lenC - i - 1]);
	}
	printf("\n");

	return 0;
}
