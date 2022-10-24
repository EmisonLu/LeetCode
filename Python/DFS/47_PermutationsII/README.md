# Permutations II

Given a collection of numbers, `nums`, that might contain duplicates, return all possible unique permutations in any order.

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

## Solution

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        def dfs(path, nums):
            if nums == []:
                res.append(path)
                return
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                dfs(path + [nums[i]], nums[:i] + nums[i+1:])
        dfs([], nums)
        return res
```

The solution is trivial, mark some interesting notes about Python:

```python
a = 0
res = []

def f1():
    res.append(1)

    global a  # highlight
    a = a + 1

    b = 0
    def f2():
        nonlocal b  # highlight
        b = b + 1
    f2()

f1()
```

