w = input()
r = int(input())
c = int(input())
grid = []
for _ in range(r):
    grid.append(input().split())

count = 0

offset = [
    [0, 1],
    [1, 1],
    [1, 0],
    [1, -1],
    [0, -1],
    [-1, -1],
    [-1, 0],
    [-1, 1]
]

for i in range(r):
    for j in range(c):
        if grid[i][j] == w[0]:
            for k in range(8):
                t = grid[i][j]
                for a in range(1, len(w)):
                    x = i + offset[k][0] * a
                    y = j + offset[k][1] * a
                    if 0 <= x < r and 0 <= y < c:
                        t += grid[x][y]
                if w == t:
                    count += 1
                for a in range(2, len(w)):
                    t = grid[i][j]
                    for b in range(1, a):
                        x = i + offset[k][0] * b
                        y = j + offset[k][1] * b
                        if 0 <= x < r and 0 <= y < c:
                            t += grid[x][y]
                    for d in range(1, len(w) - a + 1):
                        x = i + offset[k][0] * (a - 1) + offset[(k + 2) % 8][0] * d
                        y = j + offset[k][1] * (a - 1) + offset[(k + 2) % 8][1] * d
                        if 0 <= x < r and 0 <= y < c:
                            t += grid[x][y]
                    if w == t:
                        count += 1
                    t = t[:a]
                    for d in range(1, len(w) - a + 1):
                        x = i + offset[k][0] * (a - 1) + offset[(k + 6) % 8][0] * d
                        y = j + offset[k][1] * (a - 1) + offset[(k + 6) % 8][1] * d
                        if 0 <= x < r and 0 <= y < c:
                            t += grid[x][y]
                    if w == t:
                        count += 1

print(count)
