# Sort Colors

Given an array `nums` with `n` objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

**Example 1:**

```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

My solution is following, but it is a one-pass algorithm using constant extra space.

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        res = defaultdict(int)
        for i in nums:
            res[i] += 1
        for i in range(0, res[0]):
            nums[i] = 0
        for i in range(res[0], res[0] + res[1]):
            nums[i] = 1
        for i in range(res[0] + res[1], len(nums)):
            nums[i] = 2
```

Below is a one-pass algorithm using constant extra space.

```python
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        u = v = 0
        for i in range(len(nums)):
            temp = nums[i]
            nums[i] = 2
            if temp < 2:
                nums[v] = 1
                v += 1
            if temp == 0:
                nums[u] = 0
                u += 1
```

`[0, u)` is 0, `[u, v)` is 1, `[v, len(nums))` is 2.