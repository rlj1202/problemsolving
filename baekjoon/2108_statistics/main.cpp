#include <cstdio>
#include <algorithm>

using namespace std;

int values[500005];

int sum;

int maxcount;
int frequentValue;
bool updated;

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", values + n);
	}

	sort(values, values + N);

	int prev = values[0];
	int count = 0;

	for (int n = 0; n < N + 1; n++) {
		if (prev == values[n]) {
			count++;
		} else {
			if (maxcount < count) {
				maxcount = count;

				frequentValue = prev;
				updated = false;
			} else if (maxcount == count) {
				if (!updated && frequentValue < prev) {
					updated = true;
					frequentValue = prev;
				}
			}

			prev = values[n];
			count = 1;
		}

		sum += values[n];
	}

	printf("%.0f\n", (double) sum / N);
	printf("%d\n", values[N / 2]);
	printf("%d\n", frequentValue);
	printf("%d\n", values[N - 1] - values[0]);

	return 0;
}
