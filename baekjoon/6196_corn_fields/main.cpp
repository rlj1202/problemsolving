#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 100000000;

int M, N;
int grid[26][14];

int dp[26][5003]; // dp[row][flag] : the number of outcomes when row has state of flag. e.g.) dp[1][0xF] menas state of first row is "1 1 1 1".

/*
 * prev - flags of previous row
 * row - current row
 * col - current col
 * flag - current flag
 *
 * If col reaches width of the grid, that means the row has been set.
 * Then the function will call itself recursively about next row and passes current flag as previous flag.
 *
 * If col is less than width of the grid, It will call itself recursively until col reaches width of the grid.
 *
 * If row exceeds height of the grid, it is regarded as one outcome. Returns 1.
 */
long long func(int prev, int row, int col, int flag) {
	if (col == N) { // if col reaches width of the grid
		if (dp[row][flag] != -1) return dp[row][flag]; // if the value is already evaluated, return saved value.

		return dp[row][flag] = func(flag, row + 1, 0, 0); // passes current flag as previous flag
	} else {
		if (row == M + N) return 1; // row exceeds height of the grid.

		long long result = func(prev, row, col + 1, flag); // set grid[row][col + 1] = 0

		if (grid[row][col + 1] == 1 &&
				(prev & (1 << col)) == 0 &&
				(prev & (1 << (col + 1))) == 0) { // if conditions are met, set grid[row][col + 1] = 1
			result += func(prev, row, col + 1, flag | (1 << (col + 1)));
			result %= MOD;
		}

		return result;
	}
}

int main() {
	scanf("%d %d", &M, &N);
	for (int r = 1; r <= M; r++)
		for (int c = 1; c <= N; c++)
			scanf("%d", &grid[r + c - 1][c]); // add c - 1 to row so that one row can represents one digonal line of the orignal grid.

	/*
	 * Let's say below is the input.
	 *
	 *   2 3
	 *   1 1 1
	 *   0 1 0
	 *
	 * This means grid has two rows and three columns.
	 * I will call this grid as Ori[][]. ("Ori" for 'orignal')
	 * 
	 * First, convert the grid like this:
	 *
	 *   1
	 *   0 1
	 *     1 1
	 *       0
	 *
	 * and fill zeros to empty spaces.
	 *
	 *   1 0 0
	 *   0 1 0
	 *   0 1 1
	 *   0 0 0
	 *
	 * I will call this grid as Conv[][]. ("Conv" for 'Converted')
	 * 
	 * Now, each row does match to digonal lines from original grid.
	 * And we have to switch 1 to 0 following some rules.
	 *
	 * - conv[r][c] must be 0 if conv[r - 1][c] = 1 or conv[r - 1][c - 1] = 1.
	 * - if conv[r - 1][c] and conv[r - 1][c - 1] are both zero, then conv[r][c] can be either 1 or 0.
	 *
	 * Following the rules, we have to count the number of outcomes.
	 * Now we can know that if once some row is set, the number of outcomes below the row never change.
	 * That means we can store that value and use it later.
	 */

	memset(dp, -1, sizeof(dp));
	printf("%lld\n", func(0, 0, N, 0));

	return 0;
}
