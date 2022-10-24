from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row, col = [False]*len(matrix), [False]*len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True
        for i in range(len(row)):
            if row[i] == True:
                for j in range(len(matrix[0])):
                    matrix[i][j] = 0
        for i in range(len(col)):
            if col[i] == True:
                for j in range(len(matrix)):
                    matrix[j][i] = 0


matrix = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
s = Solution()
s.setZeroes(matrix)
print(matrix)
