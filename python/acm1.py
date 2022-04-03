import math
def primeFactors(n):
    primeFact = []
    while n % 2 == 0:
        primeFact.append(2),
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            primeFact.append(i),
            n = n / i
    if n > 2:
        primeFact.append(n)
    if list(set(primeFact)) == primeFact:
        return 1
    return 0
noOfTestCases = int(input())
for _ in range(noOfTestCases):
    L,R = map(int,input().split())
    res = 0
    for i in range(L,R+1):
        if i == 1:
            continue
        res += primeFactors(i)
    print(res)




