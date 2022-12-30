

n = 6

i = 1
j = 1
k = 0
c = 0
state = 0
mass = [[x for x in range(0,6)],[x for x in range(6,12)],[x for x in range(12,18)],[x for x in range(18,24)],[x for x in range(24,30)],[x for x in range(30,36)]]
mass = [x for x in range(0,n * n)]
print(mass)
print(mass[c])
k += 1
while (k < n * n):
    if state == 0:
        while (j != 1 and i != n):
            j -= 1
            i += 1
            k += 1
            c = (i - 1) * n + (j - 1)
            print(mass[c])
        if i < n:
            i += 1
            k += 1
            c = (i - 1) * n + (j - 1)
            print(mass[c])
        else: 
            j += 1
            k += 1
            c = (i - 1) * n + (j - 1)
            print(mass[c])
        state = 1
    if state == 1:
        while (j != n and i != 1):
            j += 1
            i -= 1
            k += 1
            c = (i - 1) * n + (j - 1)
            print(mass[c])
        if j < n:
            j += 1
            k += 1
            c = (i - 1) * n + (j - 1)
            print(mass[c])
        else:
            i += 1
            k += 1
            c = (i - 1) * n + (j - 1)
            print(mass[c])
        state = 0

    
    
