from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        def dfs(path, nums):
            if nums == []:
                res.append(path)
                return
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                dfs(path + [nums[i]], nums[:i] + nums[i+1:])
        dfs([], nums)
        return res


s = Solution()
print(s.permuteUnique([1, 1, 2]))
