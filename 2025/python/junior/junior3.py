n = int(input())

for _ in range(n):
    s = input()
    total = 0
    current = 0
    uppercases = ""
    negative = False
    for c in s:
        if c.isalpha():
            if negative:
                total -= current
            else:
                total += current
            current = 0
            negative = False
            if c.isupper():
                uppercases += c
        elif c == '-':
            if negative:
                total -= current
            else:
                total += current
            current = 0
            negative = True
        elif c.isdigit():
            current = current * 10 + int(c)
    if negative:
        total -= current
    else:
        total += current
    print(uppercases + str(total))
