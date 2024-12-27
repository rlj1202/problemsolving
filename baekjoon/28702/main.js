const lines = require('fs').readFileSync(0).toString().trim().split('\n');

const idx = lines.findIndex(value => !isNaN(+value));
const next = +lines[idx] + 3 - idx;

const mulOf3 = next % 3 === 0;
const mulOf5 = next % 5 === 0;

if (mulOf3 && mulOf5) console.log('FizzBuzz');
else if (mulOf3) console.log('Fizz');
else if (mulOf5) console.log('Buzz');
else console.log(next);
