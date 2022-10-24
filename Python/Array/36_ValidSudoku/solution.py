from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            container1 = {}
            container2 = {}
            for j in range(9):
                if board[i][j] in container1 or board[j][i] in container2:
                    return False
                if board[i][j] != ".":
                    container1[board[i][j]] = 1
                if board[j][i] != ".":
                    container2[board[j][i]] = 1
        for i in range(0, 7, 3):
            for j in range(0, 7, 3):
                container = {}
                for k in range(i, i+3):
                    for v in range(j, j+3):
                        if board[k][v] in container:
                            return False
                        if board[k][v] != ".":
                            container[board[k][v]] = 1
        return True


board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8",
                                                                                                                                                                                                      ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", "", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]

s = Solution()
print(s.isValidSudoku(board))
