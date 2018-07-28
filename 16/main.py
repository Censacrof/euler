import math

def get_nth_digit(number, n):
    return number // 10**n % 10

n = 2**1000
n_digits = int(math.ceil(math.log10(n)))

_sum = 0
for i in range(n_digits + 1):
    _sum += get_nth_digit(n, i)

print(_sum)