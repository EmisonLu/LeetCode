from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(index, i, j) -> bool:
            if index == len(word):
                return True
            temp, board[i][j] = board[i][j], ''
            if i-1 >= 0 and board[i-1][j] == word[index]:
                if dfs(index+1, i-1, j):
                    return True
            if j-1 >= 0 and board[i][j-1] == word[index]:
                if dfs(index+1, i, j-1):
                    return True
            if i+1 < len(board) and board[i+1][j] == word[index]:
                if dfs(index+1, i+1, j):
                    return True
            if j+1 < len(board[0]) and board[i][j+1] == word[index]:
                if dfs(index+1, i, j+1):
                    return True
            board[i][j] = temp
            return False

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0] and dfs(1, i, j):
                    return True
        return False


s = Solution()
print(s.exist([["A", "A", "A", "A", "A", "A"], ["A", "A", "A", "A", "A", "A"], ["A", "A", "A", "A", "A", "A"], [
      "A", "A", "A", "A", "A", "A"], ["A", "A", "A", "A", "A", "A"], ["A", "A", "A", "A", "A", "A"]], "AAAAAAAAAAAABAA"))
