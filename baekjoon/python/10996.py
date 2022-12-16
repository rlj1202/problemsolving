N = int(input())

if N == 1:
    print('*')
    exit()

for i in range(N * 2):
    for j in range(N):
        print('* '[(i + j) % 2], end='')
    print()
