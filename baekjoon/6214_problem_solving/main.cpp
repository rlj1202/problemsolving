#include <iostream>

const int INF = 0x3f3f3f3f;

int M, P;
int befores[302];
int afters[302];

int delta_afters[302];
int months[302];

int main() {
	scanf("%d %d", &M, &P);
	for (int p = 1; p <= P; p++) scanf("%d %d", befores + p, afters + p);

	befores[0] = INF;
	afters[0] = INF;
	months[0] = 1;

	for (int p = 1; p <= P; p++) {
		int sum_before = 0; // to accumulate
		int sum_after = 0;

		int cur_after = 0; // to store answer
		int cur_month = INF;

		for (int q = p; q >= 1; q--) {
			if (befores[q] + sum_before <= M && afters[q] + sum_after <= M) {
				sum_before += befores[q];
				sum_after += afters[q];

				int new_month = months[q - 1] + 2;
				if (sum_before + afters[q - 1] + delta_afters[q - 1] <= M) new_month--;

				// Note: if 'month' is same, then less 'after' is better.

				if (cur_month > new_month) {
					cur_after = sum_after;
					cur_month = new_month;
				}
			} else break;
		}

		// save values
		months[p] = cur_month;
		delta_afters[p] = cur_after - afters[p];
	}

	printf("%d\n", months[P]);

	return 0;
}
