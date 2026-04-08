#include <array>
static const int _ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::array<int, 26> count{};
        for (int i = 0; i < s.size(); i++) {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for (int val : count) {
            if (val != 0) return false;
        }
        return true;
     }
};
