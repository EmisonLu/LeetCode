from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        left = [0, 0]
        right = [n-1, n-1]
        matrix = [[0]*n for _ in range(n)]
        j = 1
        while j <= n*n:
            for i in range(left[1], right[0]+1):
                matrix[left[0]][i] = j
                j += 1
            for i in range(left[0]+1, right[1]+1):
                matrix[i][right[0]] = j
                j += 1
            for i in range(right[0]-1, left[1]-1, -1):
                matrix[right[1]][i] = j
                j += 1
            for i in range(right[1]-1, left[0], -1):
                matrix[i][left[1]] = j
                j += 1
            left[0] += 1
            left[1] += 1
            right[0] -= 1
            right[1] -= 1
        return matrix


s = Solution()
print(s.generateMatrix(5))
