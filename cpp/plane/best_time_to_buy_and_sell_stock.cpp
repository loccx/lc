#include <iostream>

using namespace std;

/*
int best_time(const vector<int> &ref) {
    int maxProfit = 0, currProfit = 0;
    int left = 0, right = 0;

    while (right < (int)ref.size()) {
        right++;
        currProfit = ref[right] - ref[left];
        maxProfit = max(maxProfit, currProfit);
        if (ref[right] < ref[left]) {
            left = right;
            right++;
        }
    }
    return maxProfit;
}
*/

int best_time(const vector<int> &vec) {
    int left, right = 0;
    int max_prof = 0;

    while (right < int(vec.size())) {
        right++;

        if (vec[right] > vec[left]) {
            max_prof = max(vec[right] - vec[left], max_prof);
        }
        else if (vec[right] < vec[left]) {
            left = right;
        }
    }
    return max_prof;
}

int main() {
    vector<int> input = {7,1,5,3,6,4};
    int ans;
    ans = best_time(input);
    cout << "maximum profit: " << ans << '\n';
    return 0;
}
