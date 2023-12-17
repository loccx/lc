#include <iostream>

using namespace std;

/*
vector<vector<int>> subsets(vector<int> &input) {
    vector<vector<int>> out;
    vector<int> temp;

    out.push_back({});
    int outSize;
    for (int k = 0; k < int(input.size()); k++) {
        outSize = int(out.size());
        for (int x = 0; x < outSize; x++) {
            temp = out[x];
            temp.push_back(input[k]);
            out.push_back(temp);
        }
    }

    return out;
}
*/

vector<vector<int>> subsets(vector<int> &vec) {
    vector<vector<int>> res;
    vector<int> curr;
    res.push_back({});

    for (int k = 0; k < int(vec.size()); k++) {
        int size = res.size();
        for (int x = 0; x < size; x++) {
            curr = res[x];
            curr.push_back(vec[k]);
            res.push_back(curr);
        }
    }

    return res;
}

int main() {
    int n;
    cout << "Size of input?\n";
    cin >> n;

    vector<int> inp(n);
    for (int k = 0; k < n; k++) {
        cin >> inp[k];
    }

    vector<vector <int>> result;

    result = subsets(inp);

    cout << "All possible subsets:\n\n";
    for (auto l1: result) {
        cout << "(";
        for (int m = 0; m < int(l1.size()); m++) {
            if (l1.size() == 1 || m == int(l1.size()) - 1) {
                cout << l1[m];
            }
            else cout << l1[m] << ", ";
        }
        cout << ")\n";
    }
    cout << '\n';

    return 0;
}
