class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";
        for (const auto& s : strs) {
            code += std::to_string(s.length()) + "#" + s;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        while (i < s.length()) {
            int j = s.find("#", i);
            strs.push_back(s.substr(j+1,stoi(s.substr(i,j))));
            i = j + stoi(s.substr(i, j)) + 1;
        }
        return strs;
    }
};
