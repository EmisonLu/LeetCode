class Solution:
    def addBinary(self, a: str, b: str) -> str:
        left = add = 0
        res = ""
        lenA, lenB = len(a), len(b)
        lenM = max(lenA, lenB)
        while left < lenA and left < lenB:
            sum = int(a[lenA-left-1]) + int(b[lenB-left-1]) + add
            add = 0 if sum <= 1 else 1
            res = str(sum % 2)+res
            left += 1
        s = a if lenA >= lenB else b
        for i in range(left, lenM):
            sum = int(s[lenM-i-1])+add
            add = 0 if sum <= 1 else 1
            res = str(sum % 2)+res
        return res if add == 0 else "1"+res


s = Solution()
print(s.addBinary("100", "110010"))
