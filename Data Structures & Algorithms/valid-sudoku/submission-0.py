class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        size = 9;
        
        for i in range(size):
            # check row
            row = [int(n) for n in board[i] if n.isdigit()]
            if len(set(row)) != len(row):
                return False
            # check column
            col = [row[i] for row in board if row[i].isdigit()]
            if len(set(col)) != len(col):
                return False

        for i in range(3):
            for j in range(3):
                sub = [n for row in board[3*i:3*(i+1)] for n in row[3*j:3*(j+1)] if n.isdigit()]
                if (len(set(sub)) != len(sub)):
                    return False
        return True