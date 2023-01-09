#include <iostream>
#include <algorithm>

using namespace std;

struct Number {
	int value;
	int count;
};

bool operator< (const Number &a, const Number &b) {
	return a.count > b.count; // backward
}

int N, K;
int arr[200005];

Number numbers[200005];
int numberSize;

int main() {
	// read input
	scanf("%d %d", &N, &K);
	for (int n = 0; n < N; n++) scanf("%d", arr + n);
	sort(arr, arr + N);

	//
	int last = arr[0];
	int len = 1;
	for (int n = 1; n <= N; n++) {
		int cur = arr[n];
		if (last != cur) {
			numbers[numberSize++] = {last, len};
			
			last = cur;
			len = 1;
		} else {
			len++;
		}
	}
	sort(numbers, numbers + numberSize);

	//
	int maxCut = 0;
	int maxIndex = 0;

	int sum = 0;
	for (int i = 0; i < numberSize; i++) {
		Number cur = numbers[i];
		sum += cur.count;
		int cuts = sum / K;
		if (cuts <= cur.count) {
			if (maxCut < cuts) {
				maxCut = cuts;
				maxIndex = i;
			}
		}
	}

	// print result
	for (int i = 0; i <= maxIndex; i++) {
		Number cur = numbers[i];
		for (int j = 0; j < cur.count / maxCut; j++) {
			printf("%d ", cur.value);
		}
	}
	printf("\n");

	return 0;
}
