grid_side = 20

grid = [
    [1 if x == 0 or y == 0 else None for x in range(grid_side + 1)] for y in range(grid_side + 1)
]


def calculate_cell(x, y):
    if grid[x][y] is not None:
        return grid[x][y]

    grid[x][y] = calculate_cell(x - 1, y) + calculate_cell(x, y - 1)
    grid[y][x] = grid[x][y]

    return grid[x][y]


    pass


print(calculate_cell(grid_side, grid_side))