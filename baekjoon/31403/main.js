const [A, B, C] = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map(i => i.trim());

console.log(+A + +B - +C);
console.log(A + B - C);
