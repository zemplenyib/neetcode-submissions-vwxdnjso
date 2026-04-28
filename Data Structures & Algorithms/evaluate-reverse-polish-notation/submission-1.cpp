class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> eval;
        string num;
        string operators = "+-*/";
        int res;
        for (auto t : tokens) {
            if (!operators.contains(t)) {
                int val = std::stoi(t);
                eval.push(val);
            } else {
                int op2 = eval.top(); eval.pop();
                int op1 = eval.top(); eval.pop();
                if (t == "+") {
                    res = op1 + op2;
                } else if(t == "-") {
                    res = op1 - op2;
                } else if(t == "*") {
                    res = op1 * op2;
                } else {
                    res = op1 / op2;
                }
                eval.push(res);
            }
        }
        return eval.top();
    }
};
