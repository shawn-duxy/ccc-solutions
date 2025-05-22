r = int(input())
c = int(input())
m = int(input())

row = [m]
tile = (r - 1) * c % m + 1
for _ in range(c):
    row.append(tile)
    tile = tile % m + 1
row.append(m)

for i in range(r - 2, -1, -1):
    next_row = [m * (r - i)]
    for j in range(c):
        mm = min(row[j], row[j + 1], row[j + 2])
        next_row.append(mm + (i * c + j) % m + 1)
    next_row.append(m * (r - i))
    row = next_row

print(min(row))
