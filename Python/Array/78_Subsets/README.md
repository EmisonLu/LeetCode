# Subsets

Given an integer array `nums` of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for i in range(len(nums) - 1, -1 , -1):
            t = []
            for j in res:
                temp = j.copy()
                temp.append(nums[i])
                t.append(temp)
            res.extend(t)
        return res
```

The solution is trivial. Here mark some notes about Python.

Some methods for `list`:

* `list.append(element)`: add a new element to the trail of the `list`.
* `list.extend(list1)`: on the basis of the original `list`, add a new `list1`.
* `list = list1 + list`: return a new `list`.
* `list += list1`: on the basis of the original `list`, add a new `list1`, similar to `extend`.
* `Note`: `list = list1` will point to the same `list`.
  * `list = list1.copy()` will get a new `list`.

The code can be simplified as below.

```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for num in nums:
            res += [s + [num] for s in res]
        return res
```