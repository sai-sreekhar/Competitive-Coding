max = 1000000010
noOfTestCases = int(input())

for testCaseNum in range(noOfTestCases):
    noOfModules = int(input())
    funFactor = [0] + [int(x) for x in input().split()]
    parent = [-1] + [int(x) for x in input().split()]

    childsums = [0] * (noOfModules + 1)
    childmins = [max] * (noOfModules + 1)

    ans = 0 
    for i in range(len(parent) - 1, 0, -1):
        to_forward = max(childmins[i], funFactor[i]) if childmins[i] != max else funFactor[i]
        ans += (childsums[i] - childmins[i]) if childmins[i] != max else 0
        childmins[parent[i]] = min(childmins[parent[i]], to_forward)
        childsums[parent[i]] += to_forward
        
    ans += childsums[0]
    print(f"Case #{testCaseNum+1}: {ans}")
