from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        dp = [[0]*col for _ in range(row)]
        dp[row-1][col-1] = grid[row-1][col-1]
        for i in range(col-2, -1, -1):
            dp[row-1][i] = dp[row-1][i+1] + grid[row-1][i]
        for i in range(row-2, -1, -1):
            dp[i][col-1] = dp[i+1][col-1] + grid[i][col-1]
        for i in range(row-2, -1, -1):
            for j in range(col-2, -1, -1):
                dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j])
        return dp[0][0]


s = Solution()
print(s.minPathSum([[1, 2, 3], [4, 5, 6]]))
