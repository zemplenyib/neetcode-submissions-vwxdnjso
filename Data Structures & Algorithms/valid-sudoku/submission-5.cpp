class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string, unordered_set<int>> rowSeen;
        unordered_map<string, unordered_set<int>> colSeen;
        unordered_map<string, unordered_set<int>> boxSeen;

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (board[r][c] == '.') continue;
                int val = board[r][c] - '0';
                string boxIdx = std::to_string(floor(r/3)) + std::to_string(floor(c/3));

                if ((rowSeen[to_string(r)].find(val) != rowSeen[to_string(r)].end()) ||
                    (colSeen[to_string(c)].find(val) != colSeen[to_string(c)].end()) ||
                    (boxSeen[boxIdx].find(val) != boxSeen[boxIdx].end())) {
                        return false;
                }
                
                rowSeen[to_string(r)].insert(val);
                colSeen[to_string(c)].insert(val);
                boxSeen[boxIdx].insert(val);
            }
        }

        return true;
    }
};
