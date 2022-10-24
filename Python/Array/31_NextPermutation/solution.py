from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        index = len(nums)-2
        while index >= 0 and nums[index] >= nums[index+1]:
            index -= 1
        if index == -1:
            nums.reverse()
            return
        left = len(nums) - 1
        while nums[left] <= nums[index]:
            left -= 1
        nums[left], nums[index] = nums[index], nums[left]
        nums[index+1:len(nums)] = nums[len(nums)-1:index:-1]


s = Solution()
print(s.nextPermutation([5, 1, 1]))

n = [1,2,3]
print(n[2:0:-1])