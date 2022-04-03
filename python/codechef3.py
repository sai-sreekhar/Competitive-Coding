T = int(input())
for _ in range(T):
    n  = int(input())
    string = input()
    subStringArr = []
    for i in range(n):
        temp = ''
        for j in range(i,n):
            temp += string[j]
            subStringArr.append(temp)
            if i == 0 and j == 0:
                val = int(temp,2)
            else:
                val = val ^ int(temp,2)
    print(val%998244353)