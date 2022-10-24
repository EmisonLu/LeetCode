from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        dp = [[] for _ in range(target+1)]
        candidates.sort()
        for i in range(1, target+1):
            for c in candidates:
                if i == c:
                    dp[i].append([i])
                    continue
                if i < c:
                    break
                for num in dp[i-c]:
                    if num[-1] <= c:
                        dp[i].append(num+[c])
        return dp[-1]


s = Solution()
print(s.combinationSum([7, 2, 3, 6], 7))
