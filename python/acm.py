noOfTestCases = int(input())
for _ in range(noOfTestCases):
    strLen = int(input())
    classStr = input()
    classArr = [x for x in classStr]
    count = 0
    for i in range(len(classStr)-1):
        if classArr[i] == classArr[i+1]:
            for j in range(i+2,len(classArr)):
                if classArr[j] != classArr[i+1]:
                    classArr[i+1],classArr[j] = classArr[j],classArr[i+1]
                    break
            count +=1 
    print(classArr)
    print(count)

