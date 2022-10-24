from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left, right = i + 1, len(nums) - 1
            while left < right:
                if nums[i] + nums[left] + nums[right] == 0:
                    if len(res) == 0:
                        res.append([nums[i], nums[left], nums[right]])
                    elif len(res) > 0 and res[-1] != [nums[i], nums[left], nums[right]]:
                        res.append([nums[i], nums[left], nums[right]])
                    left, right = left + 1, right - 1
                elif nums[i] + nums[left] + nums[right] < 0:
                    left += 1
                else:
                    right -= 1
        return res


s = Solution()
print(s.threeSum([-1, 0, 1, 2, -1, -4]))
