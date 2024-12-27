let [N, ...arr] = require('fs').readFileSync(0).toString().trim().split('\n').map(Number);

if (!N) {
    console.log(0);
    process.exit(0);
}

let delim = Math.round(N * 0.15);
arr = arr.sort((a, b) => a - b).slice(delim, arr.length - delim);
let avg = arr.reduce((a, b) => a + b) / arr.length;

console.log(Math.round(avg));
