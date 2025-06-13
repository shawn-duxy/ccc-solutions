r = int(input())
c = int(input())

patch = []

for _ in range(r):
    patch.append([*input()])

x = int(input())
y = int(input())

queue = [(x, y)]
l = 1

ss = 0
mm = 0
ll = 0

while l > 0:
    l = l - 1
    loc = queue.pop(0)
    p = patch[loc[0]][loc[1]]
    patch[loc[0]][loc[1]] = "*"
    if p == "*":
        continue
    elif p == "S":
        ss = ss + 1
    elif p == "M":
        mm = mm + 1
    else:
        ll = ll + 1

    if loc[0] > 0 and patch[loc[0] - 1][loc[1]] != "*":
        l = l + 1
        queue.append((loc[0] - 1, loc[1]))
    if loc[0] < r - 1 and patch[loc[0] + 1][loc[1]] != "*":
        l = l + 1
        queue.append((loc[0] + 1, loc[1]))
    if loc[1] > 0 and patch[loc[0]][loc[1] - 1] != "*":
        l = l + 1
        queue.append((loc[0], loc[1] - 1))
    if loc[1] < c - 1 and patch[loc[0]][loc[1] + 1] != "*":
        l = l + 1
        queue.append((loc[0], loc[1] + 1))

print(ss + 5 * mm + 10 * ll)
