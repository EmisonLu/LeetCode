from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        left = [0, 0]
        right = [len(matrix[0])-1, len(matrix)-1]
        res = []
        print(left, right)
        while left[1] <= right[0] and left[0] <= right[1]:
            for i in range(left[1], right[0]+1):
                res.append(matrix[left[0]][i])
            for i in range(left[0]+1, right[1]+1):
                res.append(matrix[i][right[0]])
            if left[0] < right[1]:
                for i in range(right[0]-1, left[1]-1, -1):
                    res.append(matrix[right[1]][i])
            if left[1] < right[0]:
                for i in range(right[1]-1, left[0], -1):
                    res.append(matrix[i][left[1]])
            left[0] += 1
            left[1] += 1
            right[0] -= 1
            right[1] -= 1
        return res


s = Solution()
print(s.spiralOrder([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]))
