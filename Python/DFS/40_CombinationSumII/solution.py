from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res, n = [], len(candidates)
        candidates.sort()

        def dfs(path, sum, index):
            if sum > target:
                return -1
            if sum == target:
                res.append(path)
                return 0
            for i in range(index, n):
                if i > index and candidates[i] == candidates[i-1]:
                    continue
                if dfs(path + [candidates[i]], sum + candidates[i], i + 1) == -1:
                    break
        dfs([], 0, 0)
        return res


s = Solution()
print(s.combinationSum2([2, 5, 2, 1, 2], 5))
