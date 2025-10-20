n = int(input())

spiciness = 0

for _ in range(n):
    pepper = input()
    if pepper == "Poblano":
        spiciness += 1500
    elif pepper == "Mirasol":
        spiciness += 6000
    elif pepper == "Serrano":
        spiciness += 15500
    elif pepper == "Cayenne":
        spiciness += 40000
    elif pepper == "Thai":
        spiciness += 75000
    elif pepper == "Habanero":
        spiciness += 125000

print(spiciness)