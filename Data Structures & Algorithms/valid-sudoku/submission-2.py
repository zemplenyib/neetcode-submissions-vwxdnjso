class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = len(board)

        row_seen = defaultdict(set)
        col_seen = defaultdict(set)
        box_seen = defaultdict(set)

        for row in range(n):
            for col in range(n):
                element = board[row][col]
                if element == '.':
                    continue

                if ( element in row_seen[row]
                    or element in col_seen[col]
                    or element in box_seen[row // 3, col // 3]):
                    return False
                
                row_seen[row].add(element)
                col_seen[col].add(element)
                box_seen[(row // 3, col // 3)].add(element)
        
        return True
        