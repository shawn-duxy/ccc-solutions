d = int(input())
e = int(input())

for _ in range(e):
    e = input()
    q = int(input())
    if e == "+":
        d += q
    else:
        d -= q

print(d)
