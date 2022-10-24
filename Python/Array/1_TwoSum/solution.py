from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for i, element in enumerate(nums):
            if target - element in table:
                return [table[target-element], i]
            table[element] = i


s = Solution()
print(s.twoSum([3, 2, 4], 6))
