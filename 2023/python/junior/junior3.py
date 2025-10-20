n = int(input())

days = []
for _ in range(n):
    s = input()
    days.append(s)

best = 0
attendance = []

for i in range(5):
    d = 0
    for j in range(n):
        if days[j][i] == 'Y':
            d += 1
    if d > best:
        best = d
        attendance = [i + 1]
    elif d == best:
        attendance.append(i + 1)

print(",".join(str(a) for a in attendance))