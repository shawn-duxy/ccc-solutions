c = int(input())

row1 = list(map(int, input().split()))
row2 = list(map(int, input().split()))

total = 0
for i in range(c):
    if row1[i] == 1:
        total += 3
    if row2[i] == 1:
        total += 3
    if i % 2 == 0 and row1[i] == 1 and row2[i] == 1:
        total -= 2
    if i < c - 1 and row1[i] == 1 and row1[i + 1] == 1:
        total -= 2
    if i < c - 1 and row2[i] == 1 and row2[i + 1] == 1:
        total -= 2

print(total)