#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_LEN 20

using namespace std;

int T;
int N;
int x[MAX_LEN];
int y[MAX_LEN];

int al(int *arr, int len) {
	int l[MAX_LEN];
	int r[MAX_LEN];

	int sumL = 0;
	int sumR = 0;

	for (int i = 0; i < len; i += 2) {
		l[i / 2] = arr[i];
		r[i / 2] = arr[i + 1];
		sumL += arr[i];
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
	
	int result = abs(sumL - sumR);
	return result;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		for (int n = 0; n < N; n++)
			scanf("%d %d", x + n, y + n);

		double sumX = al(x, N);
		double sumY = al(y, N);

		double distance = sqrt(sumX * sumX + sumY * sumY);
		printf("%.12lf\n", distance);
	}

	return 0;
}
