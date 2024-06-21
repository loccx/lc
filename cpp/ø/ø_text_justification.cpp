#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int max_width) {
        vector<string> res;
        vector<string> line;
        int width=0;

        for(string w:words){
            if(w.length()+width+line.size()>max_width){
                for(int k=0;k<max_width-width;k++){
                    line[k % (line.size()-1 ? line.size()-1 : 1)]+=' ';
                }
                res.push_back("");
                for(string c:line)res.back()+=c;
                line.clear();
                width=0;
            }
            line.push_back(w);
            width+=w.length();
        }

        string last_line = "";
        for(string c:line){
            c+=' ';
            last_line+=c;
        }
        last_line = last_line.substr(0,last_line.length()-1);
        while(last_line.length()<max_width)last_line+=' ';
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

