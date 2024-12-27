const input = require('fs').readFileSync(0).toString().trim()
    .split('\n')
    .map(i => i.split(' ').map(Number));

const [[V], ...list] = input;

const arr = new Array(V + 1).fill().map(() => []);

for (const [v, ...elem] of list) {
    elem.pop();
    for (let i = 0; i < elem.length; i += 2) {
        const [u, d] = elem.slice(i, i + 2);
        arr[v].push([d, u]);
    }
}

function dfs(prev, cur, accum) {
    let curMax = accum, curV = cur;

    for (const [dist, next] of arr[cur]) {
        if (next === prev) continue;

        const [maxDist, v] = dfs(cur, next, accum + dist);

        if (curMax < maxDist) {
            curMax = maxDist;
            curV = v;
        }
    }

    return [curMax, curV];
}

const [, v] = dfs(0, 1, 0);
const [result] = dfs(0, v, 0);

console.log(result);
