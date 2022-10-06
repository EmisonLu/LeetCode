class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        row, col = len(word1), len(word2)
        dp = [[0]*(col+1) for _ in range(row+1)]
        for i in range(row + 1):
            dp[i][col] = row - i
        for i in range(col + 1):
            dp[row][i] = col - i
        for i in range(row-1, -1, -1):
            for j in range(col-1, -1, -1):
                if word1[i] == word2[j]:
                    dp[i][j] = min(dp[i][j+1]+1, dp[i+1][j]+1, dp[i+1][j+1])
                else:
                    dp[i][j] = min(dp[i][j+1]+1, dp[i+1][j]+1, dp[i+1][j+1]+1)
        return dp[0][0]


s = Solution()
print(s.minDistance("intention", "execution"))
