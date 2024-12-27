const input = require('fs').readFileSync(0).toString().trim().split('\n').map(Number);

const arr = [1, 1, 1];

for (let i = 0; i < 102; i++) {
    arr.push(arr[arr.length - 2] + arr[arr.length - 3]);
}

let T = input.shift();

while (T--) {
    const N = input.shift();
    console.log(arr[N - 1]);
}
