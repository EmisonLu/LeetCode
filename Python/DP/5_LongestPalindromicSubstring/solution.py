class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        start, length = 0, 1
        for i in range(n-1, -1, -1):
            dp[i][i] = True
            for j in range(i+1, n):
                if s[i] == s[j]:
                    if i+1 == j or dp[i+1][j-1]:
                        dp[i][j] = True
                        if length < j-i+1:
                            start, length = i, j-i+1
        return s[start:start+length]


s = Solution()
print(s.longestPalindrome("aacabdkacaa"))
