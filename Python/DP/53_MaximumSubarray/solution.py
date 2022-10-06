from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0]*n
        dp[-1] = nums[-1]
        for i in range(n-2, -1, -1):
            dp[i] = max(dp[i+1]+nums[i], nums[i])
        return max(dp)


s = Solution()
print(s.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
