const lines = require('fs').readFileSync(0).toString().trim().split('\n');

let T = +lines.shift();

while (T--) {
    const N = lines.shift();
    const gears = lines
        .splice(0, N)
        .map(i => i.split(' ')[1])
        .reduce((prev, cur) => {
            prev[cur] ??= 0;
            prev[cur]++;
            return prev;
        }, {});
    const answer = Object.values(gears)
        .concat(0)
        .map(i => i + 1)
        .reduce((a, b) => a * b) - 1;

    console.log(answer);
}
