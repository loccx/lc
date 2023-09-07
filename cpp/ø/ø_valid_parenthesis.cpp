class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (auto letter : s) {
            if (letter == '{' || letter == '(' || letter == '[') {
                stack.push(letter);
            }
            else if (stack.empty() || (letter == '}' && stack.top() != '{') || (letter == ')' && stack.top() != '(') || (letter == ']' && stack.top() != '[')) {
                return false;
            }
            else {
                stack.pop();
            }
        }
        return stack.empty();
    }
};
