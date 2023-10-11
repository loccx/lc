#include <iostream>

using namespace std;

int coin_change2(int sum, vector<int>& coins) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (auto coin : coins) {
        for (int k = coin; k < int(dp.size()); k++) {
            dp[k] += dp[k - coin];
        }
    }
    return dp[sum];
}

int main() {
    vector<int> coins = {3, 4};

    int outcome;
    outcome = coin_change2(15, coins);
    cout << outcome << '\n';
}
