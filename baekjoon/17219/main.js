const lines = require('fs').readFileSync(0).toString().trim().split('\n');
const [N, M] = lines.shift().split(' ').map(Number);
const passwords = lines
    .splice(0, N)
    .map(i => i.split(' '))
    .reduce((prev, [k, v]) => { prev[k] = v; return prev; }, {});

for (const line of lines) {
    console.log(passwords[line]);
}
