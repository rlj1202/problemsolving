const lines = require('fs').readFileSync(0).toString().trim().split('\n');

const [N, M] = lines.shift().split(' ').map(Number);
const map = lines;

const dr = [0, 1, 0, -1];
const dc = [1, 0, -1, 0];

const visited = new Array(N).fill().map(() => new Array(M).fill(false));

let ir = 0, ic = 0;

for (let r = 0; r < N; r++) {
    for (let c = 0; c < M; c++) {
        if (map[r][c] === 'I') {
            ir = r;
            ic = c;
        }
    }
}

const q = [];
visited[ir][ic] = true;
q.push([ir, ic]);

while (q.length) {
    const [r, c] = q.pop();

    for (let i = 0; i < 4; i++) {
        const nr = r + dr[i];
        const nc = c + dc[i];

        if (nr < 0 || nr >= N) continue;
        if (nc < 0 || nc >= M) continue;
        if (visited[nr][nc]) continue;
        if (map[nr][nc] === 'X') continue;

        visited[nr][nc] = true;
        q.push([nr, nc]);
    }
}

let answer = 0;

for (let r = 0; r < N; r++) {
    for (let c = 0; c < M; c++) {
        if (!visited[r][c] || map[r][c] !== 'P') continue;
        answer++;
    }
}

console.log(answer || 'TT');
