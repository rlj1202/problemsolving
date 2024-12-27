const input = require('fs')
    .readFileSync(0).toString().trim().split('\n')
    .map(i => i.split(' ').map(Number));

const [[N, M], ...map] = input;

let gr = 0, gc = 0;

const visited = new Array(N).fill().map(() => new Array(M).fill(-1));

for (let r = 0; r < N; r++) {
    for (let c = 0; c < M; c++) {
        if (map[r][c] === 2) {
            gr = r;
            gc = c;
        } else if (map[r][c] === 0) {
            visited[r][c] = 0;
        }
    }
}

const dr = [0, 1, 0, -1];
const dc = [1, 0, -1, 0];


const q = [[gr, gc]];
let front = 0;
visited[gr][gc] = 0;

while (q[front]) {
    const [r, c] = q[front++];

    for (let i = 0; i < 4; i++) {
        const nr = r + dr[i];
        const nc = c + dc[i];

        if (nr < 0 || nr >= N) continue;
        if (nc < 0 || nc >= M) continue;
        if (visited[nr][nc] >= 0) continue;

        q.push([nr, nc]);
        visited[nr][nc] = visited[r][c] + 1;
    }
}

for (let r = 0; r < N; r++) {
    console.log(visited[r].join(' '));
}
