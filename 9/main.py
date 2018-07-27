k = 1000

for m in range(k):
    for n in range(m):
        
        if 2 * m**2 + 2 * m * n == k:
            a = m**2 - n**2
            b = 2 * m * n
            c = m**2 + n**2

            print(a * b * c)

            break
