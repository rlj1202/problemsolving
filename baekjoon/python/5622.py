time = [
    3, 3, 3,        # 2 A B C
    4, 4, 4,        # 3 D E F
    5, 5, 5,        # 4 G H I
    6, 6, 6,        # 5 J K L
    7, 7, 7,        # 6 M N O
    8, 8, 8, 8,     # 7 P Q R S
    9, 9, 9,        # 8 T U V
    10, 10, 10, 10, # 9 W X Y Z
]

word = input()

totalTime = 0

for i in range(len(word)):
    index = ord(word[i]) - ord('A')
    totalTime += time[index]

print(totalTime)
