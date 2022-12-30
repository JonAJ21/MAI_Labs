def f(num, base):
    s = 0
    i = 1
    while num > 0:
        print(s, num)
        s = (num % base) * 10 ** i + s;
        num = num // base
        i += 1
    return s // 10

print(f(3142,3))