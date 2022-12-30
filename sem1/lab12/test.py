

num = int(input("Input your num: "))
i = 0
temp = 0
res = 0
while num > 9:
    a = num % 10
    num = num // 10
    b = num % 10
    num = num // 10
    num = ((num * 10 + abs(a - b)) * 10 + b) * 10 + a
    res = (num % 1000) * (1000 ** i) + temp
    num = num // 1000
    temp = res
    i += 1

res = num * 1000 ** i + res
print(res)

