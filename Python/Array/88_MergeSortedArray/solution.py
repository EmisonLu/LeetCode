from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(len(nums1)-1, len(nums1)-1-m, -1):
            nums1[i] = nums1[i-len(nums1)+m]
        i, j, s = len(nums1)-m, 0, 0
        while i < len(nums1) and j < n:
            if nums1[i] < nums2[j]:
                nums1[s] = nums1[i]
                i += 1
            else:
                nums1[s] = nums2[j]
                j += 1
            s += 1
        if j == n:
            for u in range(i, len(nums1)):
                nums1[s] = nums1[u]
                s, u = s+1, u+1
        if i == len(nums1):
            for u in range(j, n):
                nums1[s] = nums2[u]
                s, u = s+1, u+1


a = [1, 2, 3, 0, 0, 0]
s = Solution()
s.merge(a, 3, [2, 5, 6], 3)
