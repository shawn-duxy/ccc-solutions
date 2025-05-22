n = int(input())

runs = []
prev = None
current_run = 0
for _ in range(n):
    p = input()
    if prev is None:
        prev = p
    if prev == p:
        current_run += 1
    else:
        runs.append((prev, current_run))
        prev = p
        current_run = 1
runs.append((prev, current_run))

r = 1

for i in range(len(runs)):
    weather = runs[i]
    if weather[0] == 'S':
        r = max(r, weather[1])
    elif weather[0] == 'P' and weather[1] == 1:
        sunny_days = 1
        if i > 0:
            sunny_days += runs[i - 1][1]
        if i < len(runs) - 1:
            sunny_days += runs[i + 1][1]
        r = max(r, sunny_days)
    else:
        sunny_days = 1
        if i > 0:
            sunny_days = max(sunny_days, runs[i - 1][1] + 1)
        if i < len(runs) - 1:
            sunny_days = max(sunny_days, runs[i + 1][1] + 1)
        r = max(r, sunny_days)

if len(runs) == 1 and runs[0][0] == 'S':
    r = runs[0][1] - 1

print(r)
