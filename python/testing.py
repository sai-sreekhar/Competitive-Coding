noOfComp,noOfEqns = map(int,input().split())
quantity = list(map(int,input().split()))
eqnDict = {}
for _ in range(0,noOfEqns):
    reactant,noOfProducts = map(int,input().split())
    productArr = list(map(int,input().split()))
    for i in range(0,len(productArr),2):
        if reactant in eqnDict.keys():
            eqnDict[reactant][productArr[i+1]] = productArr[i]
        else:
            eqnDict[reactant] = {productArr[i+1]:productArr[i]}
# print(eqnDict)
for reactant in eqnDict.keys():
    for product in eqnDict[reactant].keys():
        coeff = eqnDict[reactant][product]
        quantity[product-1] += quantity[reactant-1]*coeff
    quantity[reactant-1] = 0
quantity = [x%1000000007 for x in quantity]
print(quantity)