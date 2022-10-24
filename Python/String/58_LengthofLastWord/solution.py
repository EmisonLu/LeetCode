class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        right = 0
        while right < len(s) and s[len(s)-right-1] == " ":
            right += 1
        left = right
        while left < len(s) and s[len(s)-left-1] != " ":
            left += 1
        return left - right


s = Solution()
print(s.lengthOfLastWord("moon "))
