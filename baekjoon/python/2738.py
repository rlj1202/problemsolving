N, M = map(int, input().split())

rows = []

for n in range(N):
    row = list(map(int, input().split()))
    rows.append(row)

for n in range(N):
    row = list(map(int, input().split()))

    for m in range(M):
        rows[n][m] += row[m]

for n in range(N):
    for m in range(M):
        print(rows[n][m], end=' ')
    print()
