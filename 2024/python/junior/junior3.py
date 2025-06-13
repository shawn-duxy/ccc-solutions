n = int(input())

scores = [0] * 76

for _ in range(n):
    s = int(input())
    scores[s] = scores[s] + 1

gold = 0
silver = 0
bronze = 0

for i in range(75, -1, -1):
    if scores[i] > 0 and gold == 0:
        gold = i
    elif scores[i] > 0 and silver == 0:
        silver = i
    elif scores[i] > 0 and bronze == 0:
        bronze = i
        print(i, scores[i])
        break
