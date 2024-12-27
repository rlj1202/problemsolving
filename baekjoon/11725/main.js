const input = require('fs').readFileSync(0).toString().trim().split('\n').map(i => i.split(' ').map(Number));

const [N] = input.shift();

const arr = new Array(N + 1).fill().map(() => new Array());

for (const [a, b] of input) {
    arr[a].push(b);
    arr[b].push(a);
}

const parents = new Array(N + 1).fill(0);

function recur(prev, cur) {
    parents[cur] = prev;

    for (const next of arr[cur]) {
        if (next === prev) continue;

        recur(cur, next);
    }
}

recur(0, 1);

console.log(parents.slice(2).join('\n'));
