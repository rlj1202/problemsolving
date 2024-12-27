const lines = require('fs').readFileSync(0).toString().trim().split('\n');
const N = +lines[0];
const arr = lines[1].split(' ').map(Number);

let l = 0; r = 0;
let answer = 0;
const count = {};
for (let i = 1; i <= 9; i++) count[i] = 0;
let kinds = 0;

while (r < N) {
    if (!count[arr[r]]) kinds++;
    count[arr[r++]]++;

    while (kinds > 2) {
        if (count[arr[l]] === 1) kinds--;
        count[arr[l++]]--;
    }

    answer = Math.max(answer, r - l);
}

console.log(answer);
