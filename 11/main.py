
kernel_side_size = 4

grid = []
with open('./11/grid.txt', 'r') as f:
    
    while True:
        l = f.readline()
        
        if not l:
            break

        nums_str = l.split()

        nums = []
        for num in nums_str:
            nums.append(int(num))
        
        grid.append(nums)


grid_len_y = len(grid)
grid_len_x = len(grid[0])


_max = 0
for y in range(grid_len_y - kernel_side_size):
    for x in range(grid_len_x - kernel_side_size):
        

        prod_d1 = 1
        prod_d2 = 1
        for i in range(kernel_side_size):
            prod_h = 1
            prod_v = 1
            for j in range(kernel_side_size):
                prod_h *= grid[y + i][x + j]
                prod_v *= grid[y + j][x + i]
            
            _max = max(_max, max(prod_h, prod_v))

            prod_d1 *= grid[y + i][x + i]
            prod_d2 *= grid[y + kernel_side_size - i - 1][x + i]

        _max = max(_max, max(prod_d1, prod_d2))


print(_max)