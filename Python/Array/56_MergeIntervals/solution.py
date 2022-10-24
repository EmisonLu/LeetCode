from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        intervals.sort()
        interval = intervals[0]
        for i in range(1, len(intervals)):
            if interval[1] < intervals[i][0]:
                res.append(interval)
                interval = intervals[i]
                continue
            interval[1] = max(intervals[i][1], interval[1])
        res.append(interval)
        return res


s = Solution()
print(s.merge([[1, 4], [2, 3]]))
