import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n, q = map(int, input().split())
    a = input().strip()
    b = input().strip()

    d = [0] * n
    for i in range(n):
        d[i] = (ord(b[i]) - ord(a[i])) % 26

    added = [0] * n
    added[0] = 0
    for i in range(n - 1):
        added[i + 1] = (d[i] - added[i]) % 26

    for query in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1

        if (r - l) & 1:
            if (d[r] - added[r]) % 26 == added[l] % 26:
                print("YES")
            else:
                print("NO")
        else:
            if (d[r] - added[r]) % 26 == -added[l] % 26:
                print("YES")
            else:
                print("NO")
