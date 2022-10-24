from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        index = -1
        for i in range(len(intervals)):
            if intervals[i][1] < newInterval[0]:
                res.append(intervals[i])
                continue
            if intervals[i][0] > newInterval[1]:
                index = i
                break
            newInterval = [min(intervals[i][0], newInterval[0]),
                           max(intervals[i][1], newInterval[1])]
        res.append(newInterval)
        if index != -1:
            for i in range(index, len(intervals)):
                res.append(intervals[i])
        return res


s = Solution()
print(s.insert([[1, 5]], [0, 0]))
