#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[102];
int disturbed[102];

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++) {
		scanf("%d", arr + n);
	}
	arr[0] = arr[1];
	arr[N + 1] = arr[N];

	int cnt = 0;

	int last = arr[0];
	int toggled = 0;
	for (int n = 1; n <= N + 1; n++) {
		if (last != arr[n]) {
			toggled++;
			last = arr[n];
		} else {
			if (toggled) {
				if (last == 0) toggled--;
				int houses = toggled / 2;
				cnt += houses % 2 + houses / 2;
			}

			last = arr[n];
			toggled = 0;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
