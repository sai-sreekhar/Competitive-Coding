# cook your dish here
from math import gcd
for _ in range(int(input())):
    A,B = map(int,input().split(" "))
    if A==1 or B==1:
     print(-1)
    else:
        numsGcd = gcd(A,B)
        if numsGcd != 1:
            print(0)
        else:
            print(1)