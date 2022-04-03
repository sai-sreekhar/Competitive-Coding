x = 9
def change():
    global x
    x = 10
    return x
print(change())
print(x)