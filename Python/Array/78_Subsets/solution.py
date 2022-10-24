from typing import List


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


s = Solution()
print(s.subsets([1, 2, 3]))
