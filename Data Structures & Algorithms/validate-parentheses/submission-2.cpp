class Solution {
public:
    bool isValid(string s) {
        // Define the open parens
        const set<char> OPEN_SET = {'(', '{', '['};
        // const map<char, char> CONVERT = {
        //     {')','('},
        //     {'}','{'},
        //     {']','['}
        // };

        // Every open parenthesis, pop onto stack
        // Every closed parenthesis, pop from stack 
        // return false if the open and closed do not match
        stack<char> open_parens;

        for (char c: s) {
            if (OPEN_SET.find(c) != OPEN_SET.end()) {
                open_parens.push(c);
            } else {
                if (!open_parens.empty()) {
                    char top = open_parens.top();  // safe
                    open_parens.pop();

                    switch (c) {
                        case ')':
                            if (top != '(') return false;
                            break;
                        case '}':
                            if (top != '{') return false;
                            break;  
                        case ']': 
                            if (top != '[') return false;
                            break;
                    }
                } else {
                    return false;
                }
            }
        }
        return open_parens.empty();
    }
};
