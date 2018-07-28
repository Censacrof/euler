import math

def factor(n):
    factors = []

    for i in range(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            factors.append(i)
            factors.append(n // i)
    
    return factors


def nth_triangle_number(n):
    return (n * (n + 1)) // 2

i = 0

while True:
    n = nth_triangle_number(i)
    nf = len(factor(n))

    if nf > 500:
        print('%d has %d factors' % (n, nf))
        break
    
    i += 1