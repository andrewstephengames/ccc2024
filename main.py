with open("level3_example.in", "r") as file:
    data = file.readlines()

N = int(data[0])
index = 1
for _ in range(N):
    W, H = map(int, data[index].split())
    index += 1
    lawn = [data[i].strip() for i in range(index, index + H)]
    index += H
    path = data[index].strip()
    index += 1

    visited = set()
    x, y = 0, 0
    valid = True
    for move in path:
        if move == 'S':
            y += 1
        elif move == 'W':
            y -= 1
        elif move == 'A':
            x -= 1
        elif move == 'D':
            x += 1
        if x < 0 or x >= W or y < 0 or y >= H or lawn[y][x] == 'X' or (x, y) in visited:
            valid = False
            break
        visited.add((x, y))
    if valid and len(visited) == sum(row.count('.') for row in lawn):
        print("VALID")
    else:
        print("INVALID")

