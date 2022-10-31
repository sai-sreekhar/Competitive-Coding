noOfTestCases = int(input())
while (noOfTestCases != 0):
    noOfEnemies, noOfBullets = map(int,input().split())
    enemyCapArr = list(map(int,input().split()))
    bulletPowArr = list(map(int,input().split()))
    bulletCapArr = list(map(int,input().split()))

    for i in range(0,noOfBullets):
        bulletCap = bulletCapArr[i]
        j = 0
        enemiesShot = 0
        while ((enemiesShot < bulletCap) and (j < noOfEnemies)):
            if (enemyCapArr[j] > 0):
                if (enemyCapArr[j] - bulletPowArr[i] <= 0):
                    enemyCapArr[j] = 0
                    enemiesShot += 1
                else:
                    enemyCapArr[j] = enemyCapArr[j] - bulletPowArr[i]
                    enemiesShot += 1
            j += 1
    print(*enemyCapArr)
    noOfTestCases -=1