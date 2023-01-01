for ele in range(int(input())):
    inputN,inputK = map(int,input().split())
    permutationArr = []
    for idx in range( inputN//2):
        permutationArr.append(inputN-idx)
        permutationArr.append(idx+1)
    if(inputN % 2 != 0):
        permutationArr.append(inputN//2+1)
        print(*permutationArr)
    else:
        print(*permutationArr)

        

