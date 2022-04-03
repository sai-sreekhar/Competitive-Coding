noOfTestCases = int(input())
for _ in range(noOfTestCases):
    word = input()
    i = len(word)
    j = 1
    alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    charDict = {}
    for val in range(1,27):
        charDict[alphabets[val-1]] = val
    rank = 0
    # print(charDict)
    while j <= i-1:
        rank += pow(26,j)
        j += 1
    for k in range(len(word)-1):   
        for alpha in alphabets:
            if word[k] == alpha:
                break
            else:
                x = (len(word)-k)-1
                # y = charDict[alpha]
                rank += pow(26,x)
    
    rank += (charDict[word[len(word)-1]])
    print(rank)