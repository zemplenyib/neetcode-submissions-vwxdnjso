class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> count(26,0);
        for (int i = 0; i < s.size(); i++) {
            count[s[i]-int('a')]++;
            count[t[i]-int('a')]--;
        }

        for (int val : count) {
            if (val != 0) return false;
        }
        return true;
        // std::unordered_map<char, int> s_map, t_map;
        // for (int i=0; i<s.size(); i++){
        //     s_map[s[i]]++;
        //     t_map[t[i]]++;
        // }
        // return s_map == t_map;
     }
};
