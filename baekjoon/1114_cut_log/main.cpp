#include <iostream>
#include <algorithm>

using namespace std;

int L, K, C;
int cuts[10004];

int cut(int cutL, int cutR, int logL, int logR, int remainCuts) {
	if (remainCuts == 0) return -1;

	int l = cutL;
	int r = cutR;
	int mid = (l + r) / 2;

	int target = (logL + logR) / 2;

	while (r - l > 0) {
		mid = (r + l) / 2;
		int pivot = cuts[mid];

		if (pivot == target) {
			break;
		} else if (pivot < target) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	int index = mid;
	int result = cuts[mid];
	int delta = abs(result - target);
	if (index < cutL || cutR < index) {
		return 0;
	}
	if (cutL <= mid - 1 && mid - 1 <= cutR && abs(cuts[mid - 1] - target) < delta) {
		index = mid - 1;
		result = cuts[index];
		delta = abs(result - target);
	}
	if (cutL <= mid + 1 && mid + 1 <= cutR && abs(cuts[mid + 1] - target) < delta) {
		index = mid + 1;
		result = cuts[index];
		delta = abs(result - target);
	}
	
	printf("cuts[%d] = %d, remainCuts = %d\n", index, result, remainCuts);

	if (index - 1 >= 0 && cutL <= index - 1) cut(cutL, index - 1, logL, result, remainCuts - 1);
	if (index + 1 < K && index + 1 <= cutR) cut(index + 1, cutR, result, logR, remainCuts - 1);

	return result;
}

int main() {
	scanf("%d %d %d", &L, &K, &C);

	for (int k = 0; k < K; k++) {
		scanf("%d", cuts + k);
	}

	cut(0, K - 1, 0, L, C);

	return 0;
}
