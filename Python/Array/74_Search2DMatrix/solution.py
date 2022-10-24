from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        top, bottom = 0, len(matrix)-1
        while top <= bottom:
            mid = (top+bottom)//2
            if matrix[mid][0] == target:
                return True
            if matrix[mid][0] < target:
                top = mid + 1
            else:
                bottom = mid - 1
        left, right = 0, len(matrix[0])-1
        while left <= right:
            mid = (left+right)//2
            if matrix[top-1][mid] == target:
                return True
            if matrix[top-1][mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False


s = Solution()
print(s.searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20],
      [23, 30, 34, 60], [61, 62, 63, 64]], 30))
