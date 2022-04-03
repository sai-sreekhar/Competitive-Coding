T = int(input())
for _ in range(T):
    n  = int(input())
    string = input()
    sum = 0
    res = ''
    for i in range(0,n):
        if string[i] == '1':
            sum += (i+1)
        if sum %2 == 0:
            res += '0'
        else:
            res += '1'
    print(int(res,2))
