class Solution:
    def isValid(self, s: str) -> bool:
        left = {"[": 0, "(": 1, "{": 2}
        right = {"]": 0, ")": 1, "}": 2}
        stack = []
        for i in range(len(s)):
            if s[i] in right:
                if len(stack) == 0 or left[stack.pop()] != right[s[i]]:
                    return False
            else:
                stack.append(s[i])
        return stack == []

s = Solution()
print(s.isValid("()"))
