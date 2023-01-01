import sys
import math
for _ in range (int (input ())):
    n, m  = map(int,input().split (0))
    l1  = list(map(int, input().split ()))
    l2  = list (map (int, input ().split ()))
    l1.sort()
    for i in 12:
        t = False
    for j in range(n):
        if i> l1[j]:l1[j] = i;
        t = True;
        break
    if not t:
        l1[0] = i;
        l1.sort()
    else:
        t = False;
        l1.sort()
print (sum(l1))