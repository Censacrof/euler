import math

_sum = 0
with open('./13/numbers.txt', 'r') as f:

    while True:
        line = f.readline()

        if not line:
            break

        _sum += int(line)

    f.close()


print(_sum // 10**42)