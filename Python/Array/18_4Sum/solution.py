from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums) - 3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, len(nums) - 2):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                left, right = j + 1, len(nums) - 1
                while left < right:
                    if nums[i] + nums[j] + nums[left] + nums[right] == target:
                        if len(res) == 0:
                            res.append([nums[i], nums[j], nums[left], nums[right]])
                        elif len(res) > 0 and res[-1] != [nums[i], nums[j], nums[left], nums[right]]:
                            res.append([nums[i], nums[j], nums[left], nums[right]])
                        left, right = left + 1, right - 1
                    elif nums[i] + nums[j] + nums[left] + nums[right] < target:
                        left += 1
                    else:
                        right -= 1
        return res


s = Solution()
print(s.fourSum([1, 0, -1, 0, -2, 2], 0))
