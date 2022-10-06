from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for _ in range(n+1)]
        dp[0] = [""]
        for i in range(1, n+1):
            for j in range(0, i):
                for k in range(0, len(dp[j])):
                    for l in range(0, len(dp[i-1-j])):
                        dp[i].append("("+dp[j][k]+")"+dp[i-1-j][l])
        return dp[n]


s = Solution()
print(s.generateParenthesis(8))
