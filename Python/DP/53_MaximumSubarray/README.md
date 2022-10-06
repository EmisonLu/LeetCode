# Maximum Subarray

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

## Analysis

suffix `dp[i:]`

1. Defining subproblems

   * `dp[i]`: the largest sum of the subarray beginning from `nums[i]`
   * \# subproblems = $O(n)$

2. Guessing

3. Recurrence

   * `dp[i] = max(dp[i+1]+nums[i], nums[i])`
   * Initial condition: `dp[n-1] = sum[n-1]`
      * Cost per subproblem = $O(1)$

4. Topological order

   ```python
   for i in range(n-2, -1, -1):
   ```

5. Original problem: `dp[0]`


Total Time: $O(n)$

## Code

```python
from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0]*n
        dp[-1] = nums[-1]
        for i in range(n-2, -1, -1):
            dp[i] = max(dp[i+1]+nums[i], nums[i])
        return max(dp)
```

Note:

* The `sum()` function is useful.