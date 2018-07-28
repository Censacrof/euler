


lines = []
with open('./67/triangle.txt', 'r') as f:
    while True:
        line = f.readline()
        
        if not line:
            break
        
        nums_str = line.split()

        lines.append([int(n) for n in nums_str])

    f.close()


n_lines = len(lines)

for i in range(n_lines - 2, -1, -1):
    for j in range(len(lines[i])):
        lines[i][j] += max(lines[i + 1][j], lines[i + 1][j + 1])

print(lines[0][0])

