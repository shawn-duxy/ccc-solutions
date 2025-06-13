s1 = input()
s2 = input()

has_silent = len(s1) > len(s2)
s3 = s1
silent_first = True
silent = "-"
silly = None
silly_replace = None

found = False

if not has_silent:
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            silly = s1[i]
            silly_replace = s2[i]
            break
else:
    for i in range(len(s1)):
        if i >= len(s2) or s1[i] != s2[i]:
            silly = s1[i]
            silly_replace = s2[i]
            break
    s3 = s1.replace(silly, silly_replace)
    for i in range(len(s3)):
        if i >= len(s2) or s3[i] != s2[i]:
            silent = s3[i]
            s3 = s3.replace(silent, "")
            if s3 == s2:
                found = True
            break
    if not found:
        silent = silly
        s3 = s1.replace(silent, "")
        for i in range(len(s3)):
            if s3[i] != s2[i]:
                silly = s3[i]
                silly_replace = s2[i]
                break

print(silly, silly_replace)
print(silent)
