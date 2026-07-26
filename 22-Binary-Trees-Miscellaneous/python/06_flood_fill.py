from collections import deque
from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        original_color = image[sr][sc]
        if original_color == color:
            return image

        rows, cols = len(image), len(image[0])
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        queue = deque([(sr, sc)])
        image[sr][sc] = color

        while queue:
            r, c = queue.popleft()
            for dr, dc in directions:
                new_row, new_col = r + dr, c + dc
                if 0 <= new_row < rows and 0 <= new_col < cols and image[new_row][new_col] == original_color:
                    image[new_row][new_col] = color
                    queue.append((new_row, new_col))

        return image
