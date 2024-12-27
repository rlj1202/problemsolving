const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const str = input[0];
const i = Number(input[1]);
console.log(str[i - 1]);
