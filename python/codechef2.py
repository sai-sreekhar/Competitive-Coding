def returnXOR(string):
    if len(string) == 1:
        return string
    zeroOccur = string.count('0')
    oneOccur = string.count('1')
    if oneOccur == 0 and zeroOccur != 0:
        return '0'
    elif zeroOccur == 0 and oneOccur != 0:
        if oneOccur %2 == 0:
            return '0'
        else:
            return '1'
    else:
        if oneOccur %2 == 0:
            return '0'
        else:
            return '1'
    
T = int(input())
for _ in range(T):
    n  = int(input())
    string = input()
    arr =[]
    result = ""
    for i in range(n):
        if i == 0:
            arr.append(string[i])
        elif string[i] == '0':
                arr.append('0')
        else:
            if i%2 != 0:
                arr.append('0')
            else:
                arr.append('1')
        
        result += returnXOR(''.join(arr))
    print(int(result,2)%998244353)


