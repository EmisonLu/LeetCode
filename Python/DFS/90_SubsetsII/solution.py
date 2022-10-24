from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        
        def dfs(path, index):
            res.append(path)
            for i in range(index, len(nums)):
                if i > index and nums[i] == nums[i-1]:
                    continue
                dfs(path+[nums[i]], i+1)
        dfs([], 0)
        return res


s = Solution()
print(s.subsetsWithDup([1, 2, 2]))
