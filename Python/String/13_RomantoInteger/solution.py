class Solution:
    # def romanToInt(self, s):
    #     roman = {'M': 1000, 'D': 500, 'C': 100,
    #              'L': 50, 'X': 10, 'V': 5, 'I': 1}
    #     z = 0
    #     for i in range(0, len(s) - 1):
    #         if roman[s[i]] < roman[s[i+1]]:
    #             z -= roman[s[i]]
    #         else:
    #             z += roman[s[i]]
    #     return z + roman[s[-1]]

    def romanToInt(self, s: str) -> int:
        res = index = 0
        n = len(s)
        while index < n and s[index] == "M":
            index += 1
            res += 1000
        while index < n-1 and s[index:index+2] == "CM":
            index += 2
            res += 900
        while index < n and s[index] == "D":
            index += 1
            res += 500
        while index < n-1 and s[index:index+2] == "CD":
            index += 2
            res += 400
        while index < n and s[index] == "C":
            index += 1
            res += 100
        while index < n-1 and s[index:index+2] == "XC":
            index += 2
            res += 90
        while index < n and s[index] == "L":
            index += 1
            res += 50
        while index < n-1 and s[index:index+2] == "XL":
            index += 2
            res += 40
        while index < n and s[index] == "X":
            index += 1
            res += 10
        while index < n-1 and s[index:index+2] == "IX":
            index += 2
            res += 9
        while index < n and s[index] == "V":
            index += 1
            res += 5
        while index < n-1 and s[index:index+2] == "IV":
            index += 2
            res += 4
        while index < n and s[index] == "I":
            index += 1
            res += 1
        return res


s = Solution()
print(s.romanToInt("MCMXCIV"))
