# Combination Sum

Given an array of distinct integers `candidates` and a target integer `target`, return a list of all unique combinations of `candidates` where the chosen numbers sum to `target`*.* You may return the combinations in any order.

The same number may be chosen from `candidates` an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

**Example 1:**

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

**Example 2:**

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

**Example 3:**

```
Input: candidates = [2], target = 1
Output: []
```

## DFS Solution

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res, n = [], len(candidates)
        
        def dfs(path, sum, index):
            if sum > target:
                return
            if sum == target:
                res.append(path)
                return
            for i in range(index, n):
                dfs(path + [candidates[i]], sum + candidates[i], i)
                
        dfs([], 0, 0)
        return res 
```

For DFS (backtracking) we can remember this template, actually more or less they are fixed. So this kind of interview questions is quite easy to handle.

Complexity: I dont't know......

The solution below is faster through pruning.

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res, n = [], len(candidates)
        candidates.sort()
        def dfs(path, sum, index):
            if sum > target:
                return -1
            if sum == target:
                res.append(path)
                return
            for i in range(index, n):
                if dfs(path + [candidates[i]], sum + candidates[i], i) == -1:
                    return
        dfs([], 0, 0)
        return res
```

By the way, this question is simmilar to the Knapsack, so it can be solved by Dynamic Programming.