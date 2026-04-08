class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rowSeen;
        unordered_map<int, unordered_set<int>> colSeen;
        unordered_map<int, unordered_set<int>> boxSeen;

        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                cout << "r: " << r << " c: " << c << endl;
                cout << "idx: " << floor((r / 3))*board.size() + floor((c / 3)) << endl;
                if (board[r][c] == '.') continue;
                int val = board[r][c] - '0';

                if ((rowSeen[r].find(val) != rowSeen[r].end()) ||
                    (colSeen[c].find(val) != colSeen[c].end()) ||
                    (boxSeen[floor((r / 3))*board.size() + floor((c / 3))].find(val) != boxSeen[floor((r / 3))*board.size() + floor((c / 3))].end())) {
                        return false;
                }
                
                rowSeen[r].insert(val);
                colSeen[c].insert(val);
                boxSeen[floor((r / 3))*board.size() + floor((c / 3))].insert(val);
            }
        }

        return true;
    }
};
