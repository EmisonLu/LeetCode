from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        row, col = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0]*(col+1) for _ in range(row+1)]
        for i in range(col-1, -1, -1):
            if obstacleGrid[row-1][i] == 1:
                break
            dp[row-1][i] = 1
        for i in range(row-1, -1, -1):
            if obstacleGrid[i][col-1] == 1:
                break
            dp[i][col-1] = 1

        for i in range(row-2, -1, -1):
            for j in range(col-2, -1, -1):
                if obstacleGrid[i][j] == 0:
                    dp[i][j] = 0 if obstacleGrid[i][j] == 1 else dp[i+1][j]+dp[i][j+1]

        return dp[0][0]


s = Solution()
print(s.uniquePathsWithObstacles([[0, 0, 0], [0, 1, 0], [0, 0, 0]]))
