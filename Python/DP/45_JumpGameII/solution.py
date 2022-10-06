from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [10000]*n
        dp[n-1] = 0
        for i in range(n-2, -1, -1):
            start = i + 1
            end = i + nums[i] if i + nums[i] < n else n - 1
            for j in range(start, end+1):
                dp[i] = min(dp[i], dp[j])
            dp[i] = dp[i] + 1
        return dp[0]


s = Solution()
print(s.jump([2, 3, 1, 1, 4]))
