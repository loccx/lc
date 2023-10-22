#include <iostream>

using namespace std;

void printVec(vector<int>& vec) {
    for (auto v : vec) {
        cout << v << " ";
    }
    cout << '\n';
}

int binary_search(vector<int>& vec, int target) {

    sort(vec.begin(), vec.end());
    cout << "sorted original:\n";
    printVec(vec);

    int left = 0;
    int right = int(vec.size()) - 1;
    int mid = (left + right) / 2;

    if (vec[mid] == target) return mid;
    else if (vec[mid] > target) {
        vector<int> lowerSub = {vec.begin(), vec.begin() + mid + 1};
        cout << "lowerSub:\n";
        printVec(lowerSub);
        return binary_search(lowerSub, target);
    }
    else {
        vector<int> upperSub = {vec.begin() + mid + 1, vec.end()};
        cout << "upperSub:\n";
        printVec(upperSub);
        return binary_search(upperSub, target);
    }
    return -1;
}

int main() {
    vector<int> input = {1, 4, 6, 8, 3, 1, 4, 6, 7, 9};

    int result = binary_search(input, 6);
    cout << "result: " << result << '\n';
}
