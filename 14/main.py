

cache = {}

class node:
    val = None
    next = None
    len = None

    def __init__(self, val, next = None, len = None):
        self.val = val
        self.next = next
        self.len = len


cache.update({1: node(1, None, 1)})


def next_collatz(n):
    if n == 1:
        return None

    if n % 2 == 0:
        return n / 2
    else:
        return n * 3 + 1


def make_chain(n):
    if n in cache:
        return cache[n]

    next = next_collatz(n)
    next_node = make_chain(next)

    new_node = node(n, next_node, next_node.len + 1)

    cache.update({n: new_node})

    return new_node



for i in range(1, 1000000):
    make_chain(i)

_max = 0
start_value = None

for key, val in cache.items():
    if val.len > _max:
        _max = val.len
        start_value = val.val
        #print('%d -> %d' % (key, val.len))


print(start_value)
