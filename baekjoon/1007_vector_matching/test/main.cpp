#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <queue>

using namespace std;

static const int MIN = -100;
static const int MAX = 100;
static const int N = 8; // even number

int n[100];

bool al();
int myAl(int*, int);
int actualValue(int *arr, int len);

int main() {
	// init
	srand((unsigned int) time(NULL));

	int total = 100;
	int succeed = 0;
	for (int i = 0; i < total; i++) {
		bool result = al();
		if (result) succeed++;
		printf("################################################################################\n");
	}

	printf("\n");
	printf("Result: %.1f%%\n", (float) succeed / total * 100.0);

	return 0;
}

bool al() {
	for (int i = 0; i < N; i++) {
		int value = rand() % (MAX - MIN + 1) + MIN;

		n[i] = value;
	}

	printf("arr: ");
	for (int i = 0; i < N; i++) {
		printf("%4d", n[i]);
	}
	printf("\n");

	int my = myAl(n, N);
	int actual = actualValue(n, N);

	printf("\n");
	printf("my algorithm: %d\n", my);
	printf("actual value: %d\n", actual);

	bool result = my == actual;

	printf("\n");
	if (result) printf("Succeed\n");
	else printf("Fail\n");

	return result;
}

int actualValue(int *arr, int len) {
	sort(arr, arr + len);
	int result = 2000000009;
	do {
		int sum = 0;
		for (int i = 0; i < len; i += 2) {
			sum += arr[i + 1] - arr[i];
		}
		result = min(result, abs(sum));
	} while(next_permutation(arr, arr + len));

	return result;
}

struct Compare {
	bool operator() (int a, int b) {
		return abs(a) < abs(b);
	}
};

int myAl(int *arr, int len) {
	sort(arr, arr + len);

	int l[100];
	int r[100];

	int sumL = 0;
	int sumR = 0;

	for (int i = 0; i < len; i += 2) {
		l[i / 2] = arr[i];
		sumL += arr[i];

		r[i / 2] = arr[i + 1];
		sumR += arr[i + 1];
	}

	bool updated = true;
	while (updated) {
		updated = false;

		for (int i = 0; i < len / 2; i++) {
			for (int j = 0; j < len / 2; j++) {
				int newSumL = sumL - l[i] + r[j];
				int newSumR = sumR - r[j] + l[i];
				
				if (abs(newSumL - newSumR) < abs(sumL - sumR)) {
					int tmp = l[i];
					l[i] = r[j];
					r[j] = tmp;
					sumL = newSumL;
					sumR = newSumR;
					updated = true;
				}
			}
		}
	}

	return abs(sumL - sumR);
}
