const dr = [0, 1, 0, -1];
const dc = [1, 0, -1, 0];

const input = require('fs').readFileSync(0).toString().trim().split('\n');

const N = +input.shift();

function calc() {
    let answer = 0;

    const q = [];
    const visited = new Array(N).fill().map(() => new Array(N).fill(false));
    let front = 0;

    for (let r = 0; r < N; r++) {
        for (let c = 0; c < N; c++) {
            if (visited[r][c]) continue;

            q.push([r, c]);
            visited[r][c] = true;
            const color = input[r][c];
            answer++;

            while (q[front]) {
                const [r, c] = q[front++];

                for (let i = 0; i < 4; i++) {
                    const nr = r + dr[i];
                    const nc = c + dc[i];

                    if (nr < 0 || nr >= N) continue;
                    if (nc < 0 || nc >= N) continue;
                    if (visited[nr][nc]) continue;
                    if (input[nr][nc] !== color) continue;

                    q.push([nr, nc]);
                    visited[nr][nc] = true;
                }
            }
        }
    }

    return answer;
}

const a = calc();

for (let r = 0; r < N; r++) {
    input[r] = input[r].replaceAll('R', 'G');
}

const b = calc();

console.log(a, b);
