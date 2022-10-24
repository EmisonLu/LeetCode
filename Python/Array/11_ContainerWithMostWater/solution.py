from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        res, left, right = 0, 0, len(height) - 1
        while left < right:
            if height[left] < height[right]:
                res = max(res, height[left] * (right - left))
                left = left + 1
            else:
                res = max(res, height[right] * (right - left))
                right = right - 1
        return res

s = Solution()
print(s.maxArea([1,8,6,2,5,4,8,3,7]))