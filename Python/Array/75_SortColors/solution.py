from typing import List
from collections import defaultdict


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        u = v = 0
        for i in range(len(nums)):
            temp = nums[i]
            nums[i] = 2
            if temp == 1:
                nums[v] = 1
                v += 1
            if temp == 0:
                nums[u] = 0
                if v != u:
                    nums[v] = 1
                u += 1
                v += 1
        print(nums)


s = Solution()
s.sortColors([2, 0, 1, 1, 1])
