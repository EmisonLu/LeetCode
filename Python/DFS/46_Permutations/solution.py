from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def dfs(path, nums):
            if nums == []:
                res.append(path)
                return
            for i in range(len(nums)):
                dfs(path + [nums[i]], nums[:i] + nums[i+1:])
        dfs([], nums)
        return res


s = Solution()
print(s.permute([1, 2, 3]))
