from collections import deque

def is_valid_path(lawn, path):
    n = len(lawn)
    m = len(lawn[0])
    visited = [[False] * m for _ in range(n)]

    # Helper function to check if a position is valid
    def is_valid(x, y):
        return 0 <= x < n and 0 <= y < m and lawn[x][y] != 'X' and not visited[x][y]

    # Start at position (0, 0)
    start = (0, 0)
    visited[0][0] = True

    # Lee's algorithm
    queue = deque([start])
    while queue:
        x, y = queue.popleft()

        # Check if reached the end
        if x == n - 1 and y == m - 1:
            return True

        # Explore neighboring positions
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nx, ny = x + dx, y + dy
            if is_valid(nx, ny):
                visited[nx][ny] = True
                queue.append((nx, ny))

    return False

def main():
    with open("level3_example.in", "r") as file:
        lines = file.readlines()
        N = int(lines[0].strip())
        
        index = 1
        for _ in range(N):
            width, height = map(int, lines[index].split())
            index += 1
            
            lawn = [lines[i].strip() for i in range(index, index + height)]
            index += height
            
            path = lines[index].strip()
            index += 1
            
            if is_valid_path(lawn, path):
                print("VALID")
            else:
                print("INVALID", end="\n" if _ == N - 1 else "\n")

if __name__ == "__main__":
    main()

