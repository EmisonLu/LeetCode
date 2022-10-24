from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        end = len(nums)-1
        while end >= 0 and nums[end] == nums[0]:
            end = end-1
        rotate = end = max(end, 0)
        if nums[0] > nums[end]:
            left, right = 0, end
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
        right = rotate if nums[0] <= target else end
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False


s = Solution()
print(s.search([2, 5, 6, 0, 0, 1, 2], 0))
