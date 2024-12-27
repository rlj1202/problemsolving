const N = +require('fs').readFileSync(0).toString().trim();

const dp = new Array(N + 1).fill(Infinity);
dp[0] = 0;

for (let i = 1; i * i <= N; i++) {
    const square = i * i;
    for (let k = square; k <= N; k++) {
        dp[k] = Math.min(dp[k], dp[k - square] + 1);
    }
}

console.log(dp[N]);
