from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dic = {"2": ["a", "b", "c"], "3": ["d", "e", "f"], "4": ["g", "h", "i"], "5": ["j", "k", "l"], "6": [
            "m", "n", "o"], "7": ["p", "q", "r", "s"], "8": ["t", "u", "v"], "9": ["w", "x", "y", "z"]}
        if digits == "":
            return []
        res = dic[digits[0]]
        for i in range(1, len(digits)):
            temp = []
            for j in res:
                for k in dic[digits[i]]:
                    temp.append(j+k)
            res = temp
        return res


s = Solution()
print(s.letterCombinations("23"))
