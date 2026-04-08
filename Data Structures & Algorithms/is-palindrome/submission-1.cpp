class Solution {
public:
    bool isPalindrome(string s) {
        char *l = &s.front();
        char *r = &s.back();

        while(l < r) {
            while(l < r && !isalnum(*l)) {
                l++;
            }
            while(l < r && !isalnum(*r)) {
                r--;
            }
            if (tolower(*l) != tolower(*r)) {
                return false;
            }
            l++; r--;
        }
        return true;
    }
};
