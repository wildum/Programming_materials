import sys

def check(r):
    a = r[0]
    b = r[1]
    for i in range(min(len(a), len(b))):
        if a[i] == 'A' and b[i] != 'T':
            return False
        elif a[i] == 'T' and b[i] != 'A':
            return False
        elif a[i] == 'C' and b[i] != 'G':
            return False
        elif a[i] == 'G' and b[i] != 'C':
            return False
    return True

def backtrack(a, b, lines, L):
    for i in range(len(lines)):
        l = lines[i]
        na = a
        nb = b
        tmpa = na.replace(" ", "")
        tmpb = nb.replace(" ", "")
        if len(tmpa + l) > L:
            if len(tmpb + l) > L:
                return (-1, -1)
            nb += l + " "
            if(check((tmpa, tmpb+l)) is False):
                continue
        else:
            na += l + " "
        if i < len(lines) - 1:
            r = backtrack(na, nb, lines[:i]+lines[i+1:], L)
        else:
            r = backtrack(na, nb, lines[:i], L)
        (ta, tb) = r
        if r != (-1, -1):
            ta = ta.replace(" ", "")
            tb = tb.replace(" ", "")
            if len(ta) == len(tb) == L and check((ta, tb)):
                return r
    return (a, b)

lines = []
for line in sys.stdin:
	lines.append(line.rstrip('\n'))
	
lines = lines[1:]
L = 0
for i in lines:
    L += len(i)
L  = L//2
a=""
b=""
s = backtrack(a, b, lines, L)
ans = s[0][:-1] + "#" + s[1][:-1]
print(ans)