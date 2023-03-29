t = int(input())

for i in range(t):
    n, x, p = map(int, input().split())

    left_count = 0  # Count the number of sectors to the left of x
    right_count = 0  # Count the number of sectors to the right of x
    for j in range(p):
        f = int(input())
        if f >= x:
            right_count = max(right_count, f-x)
        if f >= n-x-1:
            left_count = max(left_count, f-(n-x-1))

    if left_count + right_count >= n:
        print("Yes")
    else:
        print("No")
