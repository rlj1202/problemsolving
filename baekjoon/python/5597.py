students = [i for i in range(1, 31)]

for _ in range(28):
    id = int(input())
    students.remove(id)

print(min(students))
print(max(students))
