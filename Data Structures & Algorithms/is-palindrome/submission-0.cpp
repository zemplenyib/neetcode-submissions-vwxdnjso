class Solution {
public:
    bool isPalindrome(string s) {
        auto it = std::remove_if(s.begin(), s.end(), [](const unsigned char c) {
            return !std::isalnum(c);
        });
        s.erase(it, s.end());
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        
        char *p1, *p2;
        p1 = &s.front();
        p2 = &s.back();
        for(int i = 0; i < floor(s.size()/2); ++i) {
            if (*p1 != *p2) return false;
            p1 ++;
            p2 --;
        }
        return true;
    }
};
