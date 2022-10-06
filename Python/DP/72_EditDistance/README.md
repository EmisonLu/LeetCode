# Edit Distance

Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` to `word2`.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character

```
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

## Analysis

Here we consider a more general situation. We define the cost for deleting `x[i]` is `cost(detete x[i])`, the cost for inserting `y[j]` is `cost(insert y[j])`, and the cost for replacing `x[i]` by `y[j]` is `cost(replace x[i] → y[j])`. In the above question, there is an implied condition, i.e. the cost for replacing the same character is 0.

suffix `x[i:]` `y[i:]`

1. Defining subproblems

   * `dp[i][j]`: the edit distance of `x[i:]` and `y[j:]`
   * \# subproblems = $O(|X||Y|)$

2. Guessing

   * How to turn x into y:
     * `x[i]` deleted
     * `y[j]` inserted
     * `x[i]` replaced by `y[j]`

3. Recurrence

   * `dp[i][j] = min(cost(detete x[i])+dp[i+1][j], cost(insert y[j])+dp[i][j+1], cost(replace x[i] → y[j])+dp[i+1][j+1])`
   * Cost per subproblem = $O(1)$

4. Topological order

   ```python
   for i in range(len(word1)-1, -1, -1):
       for j in range(len(word2)-1, -1, -1):
   ```

5. Original problem: `dp[0][0]`

Total Time: $O(|X||Y|)$

## Code

```python
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
```
