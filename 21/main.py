import math

def sum_divisors(n):

    _sum = 0

    upper = min(n, int(math.sqrt(n)))
    for i in range(1, upper):
        if n % i == 0:
            _sum += i
            _sum += n / i
    
    return _sum - n


_sum = 0
for i in range(9, 10000):
    j = sum_divisors(i)

    if i != j:
        if sum_divisors(j) == i:
            _sum += i

print(_sum)