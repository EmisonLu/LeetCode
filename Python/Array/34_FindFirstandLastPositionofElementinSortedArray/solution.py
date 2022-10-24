from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left+right)//2
            if nums[mid] == target:
                temp = mid
                while temp >= 1 and nums[temp-1] == target:
                    temp = temp-1
                while mid <= len(nums)-2 and nums[mid+1] == target:
                    mid = mid+1
                return [temp, mid]
            if nums[mid] < target:
                left = mid+1
            else:
                right = mid-1
        return [-1, -1]


s = Solution()
print(s.searchRange([5, 7, 7, 8, 8, 10], 6))
