#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::array<int8_t, 26> count{};
        for (int i = 0; i < s.size(); i++) {
            count[s[i]-int('a')]++;
            count[t[i]-int('a')]--;
        }

        for (int val : count) {
            if (val != 0) return false;
        }
        return true;
     }
};
