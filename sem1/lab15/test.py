

n = 4
mass = [[0,1,2,3],[4,5,6,7],[8,9,10,11],[12,13,14,15]]
mass = [x for x in range(0, 16)]
mass2 = [[],[],[],[]]
i = 1
j = 1
top_limit = 1
bottom_limit = n
right_limit = n
left_limit = 1
prev0 = 0
prev1 = 0
prev2 = 0
prev3 = 0
c = 0
c1 = 0
c2 = 0 
c3 = 0
state = 0
t = 0
for k in range(0, n):
    if (i == 1 and j == 1):
        c = (i - 1) * n + (j - 1)
        prev3 = prev2
        prev2 = prev1
        prev1 = prev0
        prev0 = mass[c]
        mass[c] = prev3
        t += 1
        if t < 4:
            c3 = c2
            c2 = c1
            c1 = c

        print(mass[c])
    if state == 0:
        while (j < right_limit):
            j += 1
            c = (i - 1) * n + (j - 1)
            prev3 = prev2
            prev2 = prev1
            prev1 = prev0
            prev0 = mass[c]
            mass[c] = prev3

            t += 1
            if t < 4:
                c3 = c2
                c2 = c1
                c1 = c

            print(mass[c])
        while i < bottom_limit:
            i += 1
            c = (i - 1) * n + (j - 1)
            prev3 = prev2
            prev2 = prev1
            prev1 = prev0
            prev0 = mass[c]
            mass[c] = prev3

            t += 1
            if t < 4:
                c3 = c2
                c2 = c1
                c1 = c

            print(mass[c])
        right_limit -= 1
        top_limit += 1
        state = 1
    if state == 1:
        while j > left_limit:
            j -= 1
            c = (i - 1) * n + (j - 1)
            prev3 = prev2
            prev2 = prev1
            prev1 = prev0
            prev0 = mass[c]
            mass[c] = prev3

            t += 1
            if t < 4:
                c3 = c2
                c2 = c1
                c1 = c

            print(mass[c])
        while i > top_limit:
            i -= 1
            c = (i - 1) * n + (j - 1)
            prev3 = prev2
            prev2 = prev1
            prev1 = prev0
            prev0 = mass[c]
            mass[c] = prev3

            t += 1
            if t < 4:
                c3 = c2
                c2 = c1
                c1 = c

            print(mass[c])
        left_limit += 1
        bottom_limit -= 1
        state = 0
print('------')
mass[c3] = prev2
mass[c2] = prev1
mass[c1] = prev0
print('-------------')
print(mass)

t = 0
for i in range(n):
    for j in range(n):
        print(mass[t])
        t += 1
    print('\n')