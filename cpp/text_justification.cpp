#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> cur;
        int num_of_letters = 0;

        for (string word : words) {
            if (word.size() + cur.size() + num_of_letters > maxWidth) {
                for (int i = 0; i < maxWidth - num_of_letters; i++) {
                    cur[i % (cur.size() - 1 ? cur.size() - 1 : 1)] += ' ';
                }
                res.push_back("");
                for (string s : cur) res.back() += s;
                cur.clear();
                num_of_letters = 0;
            }
            cur.push_back(word);
            num_of_letters += word.size();
        }

        string last_line = "";
        for (string s : cur) last_line += s + ' ';
        last_line = last_line.substr(0, last_line.size()-1);  // remove trailing space
        while (last_line.size() < maxWidth) last_line += ' ';
        res.push_back(last_line);

        return res;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vecotr<string> res;
        vecotr<string> curr;
        int letter_count = 0;

        for(string w:words){
            if(w.length() + cur.length() + letter_count > maxWidth){
                for(int k=0;k<maxWidth - letter_count;k++){
                    curr[k % (curr.length() - 1 ? curr.length() - 1 : 1)] += ' ';
                }
                res.push_back("");
                for(string s:curr)res.back() += s;
                curr.clear();
                letter_count = 0;
            }
            curr.push_back(word);
            letter_count += w.length();
        }

        string last_line = "";
        for(string s:curr)last_line+=(s+' ');
        last_line = last_line.substr(0,last_line.length()-1);
        while(last_line.length()<maxWidth)last_line+=' ';
        res.push_back(last_line);
        return res;
    }
};

int main() {
    vector<string> inp = {"What","must","be","acknowledgment","shall","be"};
    int w = 16;
    Solution s;
    vector<string> res = s.fullJustify(inp,w);
    for(string s:res){
        cout<<s<<'\n';
    }
}

