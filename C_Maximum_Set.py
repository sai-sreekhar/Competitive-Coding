def jd(t4, j):
    return (t4 << (j - 2)) * 3


def nm(t4, j):
    return t4 << (j - 1)


def op(l, r, j, jk):
    t1, t2, t3 = [l - 1, r, l]
    while l <= r:
        t4 = (l + r) // 2
        if (jk(t4, j)) <= t2:
            l = t4 + 1
            t1 = t4
        else:
            r = t4 - 1
    return [t3, t1]


for _ in range(int(input())):
    n, k = map(int, input().split())
    i, j = [k, 0]
    while i >= n:
        j += 1
        i //= 2
    if j == 1:
        print(1, k - n + 1)
    else:
        m1 = op(n, k, j, jd)
        m2 = op(m1[1] + 1, k, j, nm)
        print(j, (m1[1] - m1[0] + 1) * j + m2[1] - m2[0] + 1)
