class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        const set<string> OPERATORS = {"+", "-", "*", "/"};
        
        for (string str: tokens) {
            if (OPERATORS.find(str) != OPERATORS.end()) {
                int second = operands.top();
                operands.pop();
                int first = operands.top();
                operands.pop();

                int res;
                switch (str[0]) {
                    case '+':
                        res = first + second;
                        break;
                    case '-':
                        res = first - second;
                        break;
                    case '*':
                        res = first * second;
                        break;
                    case '/':
                        res = first / second;
                        break;
                }
                operands.push(res);
            } else {
                int num = stoi(str);
                operands.push(num);
            }
        }
        return operands.top();
    }
};
