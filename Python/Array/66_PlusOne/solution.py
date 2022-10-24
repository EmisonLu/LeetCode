from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res, add = [], 1
        for i in range(len(digits)-1, -1, -1):
            sum = add + digits[i]
            add = 1 if sum == 10 else 0
            res.append(sum % 10)
        if add == 1:
            res.append(1)
        return list(reversed(res))


s = Solution()
print(s.plusOne([9, 9]))
