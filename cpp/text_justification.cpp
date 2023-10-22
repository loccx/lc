#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> final_string;
        vector<string> curr_line;
        int curr_line_length = 0;

        for (int word = 0; word < int(words.size()); word++) {
            int wordSize = words[word].size();
            if (curr_line_length + wordSize + 1 < maxWidth) { // 1 for the space
                curr_line.push_back(words[word] + " ");
                curr_line_length += (wordSize + 1);
            }
            else if (curr_line_length + wordSize == maxWidth) {
                curr_line.push_back(words[word]);
                curr_line_length += (wordSize);
            }

            int spacesLeft = maxWidth - curr_line_length;
            int x = 0;

            while (spacesLeft > 0) {
                if (x != int(curr_line.size()) - 1) curr_line[x] += " ";
                x++;
                if (x == int(curr_line.size())) x = 0;
                spacesLeft--;
            }

            string currLineString = "";

            for (auto word : curr_line) {
                currLineString += word;
            }

            final_string.push_back(currLineString);
            currLineString = "";
            curr_line.clear();
        }

        return final_string;
    }
};

int main() {
    vector<string> input;
    input.push_back("This");
    input.push_back("is");
    input.push_back("an");
    input.push_back("example");
    input.push_back("of");
    input.push_back("text");
    input.push_back("justification.");
    int w = 16;

    Solution test;
    vector<string> result = test.fullJustify(input, w);
    for (auto r : result) {
        cout << r << '\n';
    }

    cout << result.size() << '\n';
    
    return 0;
}
