from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        rotate = len(nums)-1
        if nums[0] > nums[len(nums)-1]:
            left, right = 0, len(nums)-1
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] > nums[mid+1]:
                    rotate = mid
                    break
                if nums[mid] >= nums[0]:
                    left = mid + 1
                else:
                    right = mid - 1
        left = 0 if nums[0] <= target else rotate+1
        right = rotate if nums[0] <= target else len(nums)-1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return -1


s = Solution()
print(s.search([4,5,1,2,3], 1))
