from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res, n = [], len(candidates)
        candidates.sort()
        def dfs(path, sum, index):
            if sum > target:
                return -1
            if sum == target:
                res.append(path)
                return 0
            for i in range(index, n):
                if dfs(path + [candidates[i]], sum + candidates[i], i) == -1:
                    break
        dfs([], 0, 0)
        return res


s = Solution()
print(s.combinationSum([2, 3, 6, 7], 7))
