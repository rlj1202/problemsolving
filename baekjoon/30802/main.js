const lines = require('fs').readFileSync(0).toString().trim().split('\n');
const N = +lines[0];
const arr = lines[1].split(' ').map(Number);
const [T, P] = lines[2].split(' ').map(Number);

console.log(arr.reduce((prev, cur) => prev + Math.ceil(cur / T), 0));
console.log(Math.floor(N / P), N % P);
