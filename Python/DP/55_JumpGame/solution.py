from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [False] * n
        dp[n-1] = True
        for i in range(n-2, -1, -1):
            if i + nums[i] >= n:
                dp[i] = True
                continue
            for j in range(i+1, i+nums[i]+1):
                if dp[j]:
                    dp[i] = True
                    break
        return dp[0]


s = Solution()
print(s.canJump([0, 2, 3]))
