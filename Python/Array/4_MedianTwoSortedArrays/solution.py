from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n, m = len(nums1), len(nums2)
        sum = (n+m)/2 + 1 if (n+m) % 2 == 0 else (n+m)//2 + 2
        print(sum)
        # left1, right1 = 0, n - 1
        # while left1 <= right1:
        #     mid1 = (left1 + right1) // 2
        #     mid2 = (n + m) // 2 - mid1
        #     print(mid1)
        #     print(mid2)
        #     print(mid1 + mid2)
        #     if nums1[mid1] > nums2[mid2]:
        #         right1 = mid1 - 1
        #     if nums1[mid1] < nums2[mid2]:
        #         left1 = mid1 + 1
        #     if nums1[mid1] == nums2[mid2]:
        #         break
        return 0


s = Solution()
print(s.findMedianSortedArrays([1, 3], [2]))
