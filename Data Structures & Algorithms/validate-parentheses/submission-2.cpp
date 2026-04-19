class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string op = "({[";
        string cl = ")}]";
        map<char, char> pairs = {{')','('}, {'}','{'}, {']','['}};
        for (char c : s) {
            if (op.find(c) != std::string::npos) {
                st.push(c);
            } else if (cl.find(c) != std::string::npos) {
                if(st.empty()) return false;
                char popped = st.top(); st.pop();
                if (pairs.at(c) != popped) return false;
            } else {
                return false;
            }
        }
        if (!st.empty()) return false;
        return true;        
    }
};
