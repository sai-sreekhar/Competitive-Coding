t = int(input())
while t > 0:
    t = t - 1
    x = int(input())
    booleanFlag = False
    j = 0
    num1 = 0
    num2 = 0
    # for j < 5:
    #     if not (x & (1 << j)):
    #         if x & (1 << (j + 1)):
    #             num1 += (1 << j) + (1 << j + 1)
    #             num2 += 1 << j
    #             j += 1
    #     else:
    #         booleanFlag = True
    #         break
    #     j = j + 1

    # for k < 31:
    #     if x & (1 << k):
    #         num1 += 1 << k
    #         num2 += 1 << k
    #         break
    #     k = k + 1
    while j < 32:  # start from least significant bit
        if x & (1 << j):  # if jth bit is not set
            booleanFlag = True
            break
        else:  # jth bit is set
            if x & (1 << (j + 1)):  # if (j+1)th bit is set
                num1 += (1 << j) + (1 << j + 1)  # set jth and (j+1)th bit in num1
                num2 += 1 << j  # set jth bit in num2
                j += 1
        j = j + 1
    if booleanFlag == True:
        print(-1)
        continue
    print(num1, end=" ")
    print(num2)
