#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool balanced(string& input) {
    if (input.empty()) return true;
    if (input[0] == '>') return false;

    stack<char> s;
    s.push(input[0]);
    for (int k = 1; k < int(input.length()); k++) {
        if (input[k] == '>' && s.top() == '<') {
            s.pop();
        }
        else {
            s.push(input[k]);
        }
    }
    return s.size() == 0;
}

int main() {
    string input;
    cout << "Enter string of '<' and '>':\n";
    cin >> input;

    balanced(input) ? cout << "Balanced.\n" : cout << "Not Balanced.\n";
}
