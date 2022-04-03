num = [1,2,3,4,5,6,7,8,9,10]
l1 = []
l2 = []
for i in num:
    if i == 1:
        l1.append(i)
    else:
        for j in range(1,i-1):

            if i%num[j] == 0:
                l1.append(i)
                break
        else:
            l2.append(i)

print(l1)
print(l2)