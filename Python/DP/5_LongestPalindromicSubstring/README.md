# Longest Palindromic Substring

Given a string `s`, return the longest palindromic substring in `s`.

A string is called a palindrome string if the reverse of that string is the same as the original string.

```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

## Analysis

substrings `dp[i:j]`

1. Defining subproblems

   * If `s[i:j]` is a palindrome string, then `dp[i][j] = True`, else `dp[i][j] = False`
   * \# subproblems = $O(n^2)$

2. Guessing

3. Recurrence

   * If `dp[i+1][j-1] == True`, and `s[i] = s[j]`, then `dp[i][j] == True`
   * There is a special case to handle when `i = j-1`
   * Initial condition: `dp[i, i] = True`
   * Cost per subproblem = $O(1)$

4. Topological order

   ```python
   for i in range(len(s)-1, -1, -1):
     for j in range(i+1, len(s))
   ```

5. Original problem: `max{j-i+1: dp[i][j] == True}`

Total Time: $O(n^2)$

## Code

```python
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
```

Note:

* `dp = [[False] * n for _ in range(n)]` is more effcient than `dp = [[False for _ in range(n)] for _ in range(n)]`
* `dp = [[False] * n for _ in range(n)]` is different from `dp = [[False] * n] * n`.