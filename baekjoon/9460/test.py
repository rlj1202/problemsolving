import os

dir = os.path.dirname(__file__)
path = os.path.join(dir, 'memo.txt')

f = open(path, 'w')

N = 100
K = 2

f.write('1\n')
f.write(f'{N} {K}\n')

for i in range(1, N + 1):
    f.write(f'{i} {i - 1000000} ')

f.close()