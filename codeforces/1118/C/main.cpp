#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[402];

bool odd;
int mid;

pair<int, int> nums[402];
int numslen;

int mat[22][22];

bool f(int r, int c) {
	if (c > mid) return f(r + 1, 1);
	if (r > mid) return true;

	bool result = false;

	if (r == mid && c == mid && odd) {
		for (int i = 0; i < numslen; i++) {
			if (nums[i].second < 1) continue;

			nums[i].second -= 1;
			int num = nums[i].first;

			mat[r][c] = num;

			result = f(r, c + 1);

			if (result) {
				break;
			} else {
				nums[i].second += 1;
			}
		}
	} else if ((r == mid && odd)) {
		for (int i = 0; i < numslen; i++) {
			if (nums[i].second < 2) continue;

			nums[i].second -= 2;
			int num = nums[i].first;

			mat[r][c] = num;
			mat[r][N - c + 1] = num;

			result = f(r, c + 1);

			if (result) {
				break;
			} else {
				nums[i].second += 2;
			}
		}
	} else if ((c == mid && odd)) {
		for (int i = 0; i < numslen; i++) {
			if (nums[i].second < 2) continue;

			nums[i].second -= 2;
			int num = nums[i].first;

			mat[r][c] = num;
			mat[N - r + 1][c] = num;

			result = f(r, c + 1);

			if (result) {
				break;
			} else {
				nums[i].second += 2;
			}
		}
	} else {
		for (int i = 0; i < numslen; i++) {
			if (nums[i].second < 4) continue;

			nums[i].second -= 4;
			int num = nums[i].first;

			mat[r][c] = num;
			mat[N - r + 1][N - c + 1] = num;
			mat[r][N - c + 1] = num;
			mat[N - r + 1][c] = num;

			result = f(r, c + 1);

			if (result) {
				break;
			} else {
				nums[i].second += 4;
			}
		}
	}

	return result;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N * N; n++) {
		scanf("%d", arr + n);
	}
	sort(arr, arr + N * N);

	odd = N % 2 == 1;
	mid = (N + 1) / 2;

	int prev = arr[0];
	int count = 1;
	for (int n = 1; n <= N * N; n++) {
		if (prev == arr[n]) {
			count++;
		} else {
			nums[numslen++] = {prev, count};

			prev = arr[n];
			count = 1;
		}
	}

	bool valid = f(1, 1);

	printf("%s\n", valid ? "YES" : "NO");
	if (valid) {
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				printf("%3d ", mat[r][c]);
			}
			printf("\n");
		}
	}

	return 0;
}
