from cmath import sqrt
import math
T = int(input())
for i in range(T):
    a,b = map(int,input().split())
    arr = [5,10,13,17,25,29,15]
    arr2 = []
    for i in arr:
        for j in arr:

    dist = sqrt(a*a+b*b)
    if math.floor(dist) ==  dist and math.ceil(dist) == dist:
