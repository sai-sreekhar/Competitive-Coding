for _ in range(int(input())):
    n = int(input())
    s = int("9" * n)
    x = input()
    if x[0] == "9":
        s = int("1" * (n + 1))
        print(s - int(x))
    else:
        print(s - int(x))
