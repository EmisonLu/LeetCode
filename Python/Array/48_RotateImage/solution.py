from re import A
from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        left, right = 0, n - 2
        while left <= right:
            temp = matrix[left][left:right+1]
            for i in range(left, right+1):
                matrix[left][i] = matrix[n-i-1][left]
                matrix[n-i-1][left] = matrix[n-1-left][n-i-1]
                matrix[n-1-left][n-i-1] = matrix[i][n-1-left]
                matrix[i][n-1-left] = temp[i-left]
            left += 1
            right -= 1


s = Solution()
s.rotate([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
