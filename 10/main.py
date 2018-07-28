import math

primes = [2]

def full_check(number):
    upper = int(math.sqrt(number))

    for p in primes:
        if p > upper:
            break

        if number % p == 0:
            return False
    return True


sum = 2
upper_bound = 2000000
upper_bound_pc = upper_bound // 100

for i in range(3, upper_bound, 2):
    if (i + 1) % (upper_bound_pc) == 0:
        print('%d%%' % ((i + 1) // upper_bound_pc))

    if full_check(i):
        sum += i
        primes.append(i)

print(sum)