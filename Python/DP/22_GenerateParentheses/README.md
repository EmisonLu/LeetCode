# Generate Parentheses

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

## Analysis

1. Defining subproblems

   * `dp[i]`: All combinations of well-formed parentheses when `n = i`
   * \# subproblems = $O(n)$

2. Guessing

   * The hardest part
   * When given `i` pairs of parentheses, consider the following pattern: `(A)B`
     * The pairs of parentheses which `A` may denotes are from `dp[0]` to `dp[i-1]`

3. Recurrence

   * Follow the guessing part
   * Cost per subproblem = $O(n^3)$

4. Topological order

   ```python
   for i in range(1, n+1):
       for j in range(0, i):
           for k in range(0, len(dp[j])):
               for l in range(0, len(dp[i-1-j])):
   ```

5. Original problem: `dp[n]`

Total Time: $O(n^4)$

## Code

```python
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
```
