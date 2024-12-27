const [N, M] = require('fs').readFileSync(0).toString().trim().split(' ').map(Number);

const arr = new Array(M).fill();

function recur(i, prev) {
    if (i === M) {
        console.log(arr.join(' '));
        return;
    }

    for (let n = prev; n <= N; n++) {
        arr[i] = n;
        recur(i + 1, n);
    }
}

recur(0, 1);
