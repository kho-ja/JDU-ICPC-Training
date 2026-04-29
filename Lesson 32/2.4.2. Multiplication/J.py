n = int(input())
l, r = 0, n
while l != r:
    m = (l+r+1)//2
    if m*m > n:
        r = m -1
    else:
        l = m
print(l)