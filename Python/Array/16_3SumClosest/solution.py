from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        sum = nums[0]+nums[1] + nums[2]
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left, right = i + 1, len(nums) - 1
            while left < right:
                temp = nums[i] + nums[left] + nums[right]
                if temp == target:
                    return target
                if temp < target:
                    if target-temp < abs(sum-target):
                        sum = temp
                    left += 1
                elif temp > target:
                    if temp-target < abs(sum-target):
                        sum = temp
                    right -= 1
        return sum


s = Solution()
print(s.threeSumClosest([4, 0, 5, -5, 3, 3, 0, -4, -5], -2))
