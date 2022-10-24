from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common = strs[0]
        for i in range(1, len(strs)):
            right = 0
            while right < len(strs[i]) and right < len(common) and strs[i][right] == common[right]:
                right = right + 1
            if right == 0:
                return ""
            common = common[:right]
        return common


s = Solution()
print(s.longestCommonPrefix(["flower", "flow", "flight"]))
