from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        left = right = 0
        while right < len(nums):
            count = 1
            right = right + 1
            while right < len(nums) and nums[right] == nums[right-1]:
                right,count = right + 1,count + 1
            if count == 1:
                nums[left] = nums[right-1]
                left += 1
            if count >= 2:
                nums[left:left+2] = [nums[right-1],nums[right-1]]
                left += 2
        return left


s = Solution()
print(s.removeDuplicates([1, 1, 1, 2, 2, 3]))
